#pragma warning (disable : 4996)

#include <cstdio>
#define MAX 102
#define ll long long
using namespace std;
int map[MAX][MAX];
ll dp[MAX][MAX];
int N;
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
void input() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dp[1][1] = 1;
}

void sol() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!dp[i][j]) continue;
			if (i == N && j == N) continue;
			for (int k = 0; k < 2; k++) {
				int ny = i + map[i][j] * dy[k];
				int nx = j + map[i][j] * dx[k];
				if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
				dp[ny][nx] += dp[i][j];
			}
		}
	}
}
int main() {
	input();
	sol();

	printf("%lld", dp[N][N]);
	return 0;
}