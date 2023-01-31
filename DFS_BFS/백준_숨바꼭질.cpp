#pragma warning (disable : 4996)

#include <cstdio>
#include <queue>
#define MAX 200002
using namespace std;
int N;
int K;
int ans;
int visited[MAX];
queue<int>q;
void bfs(int n) {
	q.push(n);
	while (q.size()) {
		int x = q.front(); 
		if (x == K) break;
		q.pop();
		for (int i = 0; i < 3; i++) {
			int nn;
			if (i == 0) {
				nn = x - 1;
			}
			else if (i == 1) {
				nn = x+ 1;
			}
			else {
				nn =x * 2;
			}
			if (nn < 0  || nn >= MAX || visited[nn]) continue;
			visited[nn] = visited[x] + 1;
			q.push(nn);
		}
	}
}
int main() {
	scanf("%d %d", &N, &K);
	if (N >= K) {
		printf("%d\n", N - K);
		return 0;
	}
	bfs(N);
	/*for (int i = 0; i < 10; i++) {
		printf("%d ", visited[i]);
	}*/
	printf("%d\n", visited[K]);
	return 0;
}