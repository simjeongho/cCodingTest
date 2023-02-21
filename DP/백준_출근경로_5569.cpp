#pragma warning (disable : 4996)

#include <cstdio>
#define MOD 100000
#define MAX 101
#define ll long long
using namespace std;
int w, h;
int result;
ll dp[MAX][MAX][2][2]; // 4���� dp�� ����ؾ��� 
//y��ǥ y��ǥ k���� ��ȯ ���� l���� ����
//1. dp[i][j][0][0]=������ ���ʿ��� �԰� ���� ��ȯ �Ұ��� -> ���� ������ ��ǥ dp[i][j-1][1][
//2. dp[i][j][0][1]=������ ���ʿ��� �԰� ���� ��ȯ ����
//3. dp[i][j][1][0]=������ ���ʿ��� �԰� ������ȯ�� �Ұ����� ��� dp[i][j][1][0] = dp[i-1][j][0][1]
//4. dp[i][j][1][1]=������ ���ʿ��� �԰� ���� ��ȯ�� ������ ��� dp[i][j][1][1] = dp[i-1][j][1][1] + dp[i-1][j][1][0]
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