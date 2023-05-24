#pragma warning (disable : 4996)

#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
int n;
int maps[501][501];
int dp[501][501];

int ans;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
void input() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &maps[i][j]);
		}
	}
}
int dfs(int y, int x) {
	if (dp[y][x]) return dp[y][x];
	dp[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (maps[y][x] >= maps[ny][nx]) continue;
		dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
	}
	return dp[y][x];
}
int main() {

	input();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, dfs(i, j));
		}
	}
	printf("%d\n", ans);
	return 0;
}