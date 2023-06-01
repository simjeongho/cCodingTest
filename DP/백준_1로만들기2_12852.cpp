#pragma warning (disable : 4996)
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int N;
int dp[100001];
int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		dp[i] = i;
	}

	for (int i = 2; i <= N; i++) {
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2]);
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3]);
		}
		dp[i] = min(dp[i], dp[i - 1]) + 1;
	}

	printf("%d\n", dp[N] - 1);

	while (N != 0) {
		cout << N << " ";
		if (dp[N] == dp[N - 1] + 1) {
			N = N - 1;
		}
		else if (N % 2 == 0 && dp[N] == dp[N / 2] + 1) {
			N = N / 2;
		}
		else if (N % 3 == 0 && dp[N] == dp[N / 3] + 1) {
			N = N / 3;
		}
	}
	return 0;
}