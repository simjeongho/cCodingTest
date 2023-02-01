#pragma warning (disable : 4996)
#define MAX 1002
#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int Ns[MAX];
int dp[MAX];
int ans;
void sol() {
	dp[0] = Ns[0];
	ans = dp[0];
	for (int i = 0; i < N; i++) dp[i] = Ns[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (Ns[j] < Ns[i]) {
				dp[i] = max(dp[i], dp[j] + Ns[i]);
				ans = max(ans, dp[i]);
			}
		}
	}
}
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &Ns[i]);
	}

	sol();
	printf("%d\n", ans);
	return 0;
}