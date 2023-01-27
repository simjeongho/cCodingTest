#pragma warning (disable: 4996)
/*
	���� - ���Ӱ���
	���� ���� ������ �� ����. 
	���� ���� ���������� inDegree�迭�� �߿��ϴ�. 

	�ϳ��� ��带 Ž���ϸ鼭 inDegree�� ���ش�. 
	��� ���� �� Ž���ϸ� inDegree�� 0�� ������ ������ �迭�� ���� �����ش�. 
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 502
using namespace std;
int N;
vector <int> v[MAX]; // ���� ���
int dist[MAX];
int inDegree[MAX];
int result[MAX];
void input() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int tmp = 0;
		for (int j = 0; j <= N; j++) {
			if (j == 0) {
				scanf("%d", &tmp);
				dist[i] = tmp;
			}
			else {
				scanf("%d", &tmp);
				if (tmp == -1) break;
				v[tmp].push_back(i);
				inDegree[i]++;
			}
		}
	}

	/*for (int i = 1; i <= N; i++) {
		printf("%d ", dist[i]);
	}
	printf("\n");*/
}
void topologySort() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) { 
			q.push(i); 
			result[i] = dist[i];
		} // ���� inDegree�� 0�� ���� �ִٸ� q�� �־��ش�.
	}
	if (q.empty()) return;

	while (q.size()) {
		int x = q.front(); q.pop();
		for (int a : v[x]) {
			inDegree[a]--;
			result[a] = max(result[a], result[x] + dist[a]);
			if (inDegree[a] == 0) {
				q.push(a); // q�� ����ִ´�.
			}
		}
	}
}
int main() {
	input();
	topologySort();

	for (int i = 1; i <= N; i++) {
		printf("%d\n", result[i]);
	}
	
	return 0;
}