#pragma warning (disable : 4996)

#include <cstdio>
#include <cstring>
#define MAX 502
using namespace std;

int N, M;
int maps[MAX][MAX];
int visited[MAX][MAX];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };
int ans;
int dfs(int y, int x) {
	if (y == N - 1 && x == M - 1)return 1; // 목적지에 도착하는 경우 1을 반환
	if (visited[y][x] == -1) { // 방문하지 않았다면
		visited[y][x] = 0; // 방문 표시 
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (maps[ny][nx] >= maps[y][x]) continue;
			visited[y][x] += dfs(ny, nx);
			
			//visited[ny][nx] = 0; 백트래킹은 시간초과가 난다.
		
		}
	}
	return visited[y][x]; // 현재의 값을 리턴한다. 현재 경로까지 올 수 있는 경로의 수 
}
void input() {
	memset(visited, -1, sizeof(visited)); // visited배열 초기화
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &maps[i][j]);
		}
	}
}
int main() {
	input();
	ans = dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}