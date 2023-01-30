#pragma warning (disable : 4996)

#include <cstdio>
#include <queue>
#include <tuple>
#define MAX 102
#define ll long long
using namespace std;
int N; // 게임 판의 크기
int maps[MAX][MAX];
int visited[MAX][MAX];
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };
ll ans;
queue <pair<int, int>> q;
void bfs(int y, int x) {
	visited[y][x] = 1;
	q.push({ y,x });
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 2; i++) {
			int ny = y + dy[i] * maps[y][x];
			int nx = x + dx[i] * maps[y][x];
			//printf("ny:%d nx:%d\n", ny, nx);
			if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
			if (ny == N && nx == N) {
				visited[ny][nx] += 1;
				ans++;
				continue;
			}
			visited[ny][nx] += 1;
			q.push({ ny, nx });
		}
	}
	
}
int main() {

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &maps[i][j]);
		}
	}
	bfs(1, 1);
	printf("%lld\n", ans);

	return 0;
}