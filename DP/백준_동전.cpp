#pragma warning (disable : 4996)

#include <cstdio>
#include <cstring>
using namespace std;

int T; // 테스트 케이스 횟수
int N; // 동전 개수
int coins[22]; // 동전 가지수 20 +2
int goal; // 최대 만원
int dp[22][10000 + 4];

void sol() {
	for (int j = 1; j <= goal; j++) {
		if (j % coins[1] == 0) dp[1][j] = 1;
	}// 첫 번째 열 초기화
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= goal; j++) {
			if (j < coins[i]) dp[i][j] = dp[i - 1][j];
			else {
				for (int k = j % coins[i]; k <= j; k += coins[i]) {
					dp[i][j] += dp[i-1][k];
				}
				if (j % coins[i]==0) dp[i][j]++;
			}
		}
	}
	return;
}
int main() {

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int i = 0; i < 22; i++) {
			coins[i] = 0;
		} //동전 개수 초기화
		memset(dp, 0, sizeof(dp)); // dp배열 초기화 
		for (int i = 1; i <= N; i++) {
			scanf("%d", &coins[i]);
		}
		scanf("%d", &goal); // 만들어야하는 금액 

		sol();

		/*for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= goal; j++) {
				printf("%d ", dp[i][j]);
			}
			printf("\n");
		}*/
		printf("%d\n", dp[N][goal]);
	}
	return 0;
}