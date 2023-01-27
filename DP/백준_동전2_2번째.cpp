#pragma warning (disable : 4996)
/*
	점화식 
	dp[n] = min(dp[j-arr[i]] + 1, dp[j]);
*/
#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int coins[110];
int dp[100010]; // 합이므로 100010
int n, k;
void sol() {
	for (int i = 1; i <= k; i++) {
		dp[i] = INF; // 무한대로 초기화
	}
	for (int i = 1; i <= n; i++) {
		dp[coins[i]] = 1; // 일치하는 경우는 1
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	}

	if (dp[k] == INF) {
		puts("-1");
	}
	else {
		printf("%d\n", dp[k]);
	}
}
int main() {
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &coins[i]);
	}

	sol();
	return 0;
}
