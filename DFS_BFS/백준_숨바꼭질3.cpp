#pragma warning (disable : 4996)

#include <cstdio>
#include <queue>
using namespace std;
#define MAX 200000+4
int N, K; // 수빈이와 동생의 위치
int visited[MAX];
queue<int> q;
void bfs(int n) {
	visited[n] = 1;
	q.push(n);
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		int nn = 0;
		nn = curr * 2;
		if (nn >= 0 && nn <= 100001 && !visited[nn]) {
			visited[nn] = visited[curr];
			q.push(nn);
		}
		nn = curr - 1;
		if (nn >= 0 && nn <= 100001 && !visited[nn]) {
			visited[nn] = visited[curr] + 1;
			q.push(nn);
		}
		nn = curr + 1;
		if (nn >= 0 && nn <= 100001 && !visited[nn]) {
			visited[nn] = visited[curr] + 1;
			q.push(nn);
		}
		
		//if (visited[K]) break;
	}
}
int main() {

	scanf("%d %d", &N, &K);
	bfs(N);

	/*for (int i = 0; i <= 18; i++) {
		printf("%d ", visited[i]);
	}*/
	printf("%d\n", visited[K] - 1);
	return 0;
}