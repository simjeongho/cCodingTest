#pragma warning (disable : 4996)

#include <cstdio>
#define MOD 100000
#define MAX 101
#define ll long long
using namespace std;
int w, h;
int result;
ll dp[MAX][MAX][2][2]; // 4차원 dp를 사용해야함 
//y좌표 y좌표 k방향 전환 가능 l현재 방향
//1. dp[i][j][0][0]=이전에 동쪽에서 왔고 방향 전환 불가능 -> 이전 오른쪽 좌표 dp[i][j-1][1][
//2. dp[i][j][0][1]=이전에 동쪽에서 왔고 방향 전환 가능
//3. dp[i][j][1][0]=이전에 북쪽에서 왔고 방향전환이 불가능한 경우 dp[i][j][1][0] = dp[i-1][j][0][1]
//4. dp[i][j][1][1]=이전에 북쪽에서 왔고 방향 전환이 가능한 경우 dp[i][j][1][1] = dp[i-1][j][1][1] + dp[i-1][j][1][0]
void sol() {
	scanf("%d %d", &w, &h);

	for (int i = 2; i <= w; i++) {
		dp[1][i][0][1] = 1;
	}
	for (int i = 2; i <= h; i++) {
		dp[i][1][1][1] = 1;
	}
	for (int i = 2; i <= h; i++) {
		for (int j = 2; j <= w; j++) {
			dp[i][j][1][0] = dp[i - 1][j][0][1] % MOD;
			dp[i][j][1][1] = (dp[i - 1][j][1][1] + dp[i - 1][j][1][0]) % MOD;
			dp[i][j][0][0] = dp[i][j - 1][1][1] % MOD;
			dp[i][j][0][1] = (dp[i][j - 1][0][1] + dp[i][j - 1][0][0]) % MOD;
		}
	}
}

int main() {

	sol();

	/*for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			printf("%d ", (dp[i][j][0][0] + dp[i][j][0][1] + dp[i][j][1][0] + dp[i][j][1][1]) % MOD);
		}
		printf("\n");
	}*/
	result = (dp[h][w][0][0] + dp[h][w][0][1] + dp[h][w][1][0] + dp[h][w][1][1]) % MOD;
	printf("%d\n", result);

	return 0;
}