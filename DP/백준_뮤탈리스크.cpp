#pragma warning (disable: 4996)
#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;
int N; // scv 수
int scvs[4]; // scv 체력
int dp[61][61][61];

int sol(int x, int y, int z) {
	if (x < 0) return sol(0, y, z);
	if (y < 0) return sol(x, 0, z);
	if (z < 0) return sol(x, y, 0);

	if (x == 0 && y == 0 && z == 0) return 0;
	//이미 계산했다면 바로 return한다. visited같은 역할 
	if (dp[x][y][z] != -1)return dp[x][y][z];

	// 무한대로 초기화 
	dp[x][y][z] = INF;

	// 6가지의 경우의 수 모두 돌린다. 
	dp[x][y][z] = min(dp[x][y][z], sol(x - 9, y - 3, z - 1) + 1);
	dp[x][y][z] = min(dp[x][y][z], sol(x - 9, y - 1, z - 3) + 1);
	dp[x][y][z] = min(dp[x][y][z], sol(x - 3, y - 9, z - 1) + 1);
	dp[x][y][z] = min(dp[x][y][z], sol(x - 3, y - 1, z - 9) + 1);
	dp[x][y][z] = min(dp[x][y][z], sol(x - 1, y - 9, z - 3) + 1);
	dp[x][y][z] = min(dp[x][y][z], sol(x - 1, y - 3, z - 9) + 1);

	return dp[x][y][z];
}

int a, b, c;
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &scvs[i]);
	}
	printf("%d\n", sol(scvs[0], scvs[1], scvs[2]));

	return 0;
}