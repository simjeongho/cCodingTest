#pragma warning(disable:4996)
#include <cstdio>
#include <algorithm>

#define MAX (9)

using namespace std;

int N, M;	// N개의 자연수 중에서 M개를 고른 수열
int arr[MAX];
int printArray[MAX];

bool visit[MAX];

void input();
void dfs(int idx);

int main() {
	// 1. 입력
	//freopen("input.txt", "r", stdin);
	input();

	// 2. 정렬
	sort(arr, arr + N);

	// 3. dfs 수행
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
	// ** 탈출조건
	if (idx == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", printArray[i]);
		}
		printf("\n");
		return;
	}

	// 중복체크를 위한 변수 
	int prevNumBackup = 0;
	for (int i = 0; i < N; i++) {
		if (visit[i] == false && arr[i] != prevNumBackup) {

			// ** 비내림차순을 위한 코드
			if (idx > 0 && arr[i] < printArray[idx - 1]) continue;

			printArray[idx] = arr[i];
			prevNumBackup = printArray[idx];	// 전역변수 배열 값 변할 수 있으므로 백업
			visit[i] = true;
			dfs(idx + 1);
			visit[i] = false;

		}
	}

}