#pragma warning(disable:4996)
#include <cstdio>
#include <algorithm>

#define MAX (9)

using namespace std;

int N, M;	// N���� �ڿ��� �߿��� M���� �� ����
int arr[MAX];
int printArray[MAX];

bool visit[MAX];

void input();
void dfs(int idx);

int main() {
	// 1. �Է�
	//freopen("input.txt", "r", stdin);
	input();

	// 2. ����
	sort(arr, arr + N);

	// 3. dfs ����
	dfs(0);

	return 0;
}

void input() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
}

void dfs(int idx) {
	// ** Ż������
	if (idx == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", printArray[i]);
		}
		printf("\n");
		return;
	}

	// �ߺ�üũ�� ���� ���� 
	int prevNumBackup = 0;
	for (int i = 0; i < N; i++) {
		if (visit[i] == false && arr[i] != prevNumBackup) {

			// ** �񳻸������� ���� �ڵ�
			if (idx > 0 && arr[i] < printArray[idx - 1]) continue;

			printArray[idx] = arr[i];
			prevNumBackup = printArray[idx];	// �������� �迭 �� ���� �� �����Ƿ� ���
			visit[i] = true;
			dfs(idx + 1);
			visit[i] = false;

		}
	}

}