#pragma warning (disable : 4996)

#include <cstdio>
#include <algorithm>
#define MAX 202
using namespace std;
int N; //아이들 수
int dp[MAX];
int origin[MAX];
int mx;
int ans;
void input() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &origin[i]);
	}
}

void sol() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (origin[i] >= origin[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
				mx = max(mx, dp[i]);
			}
		}
	}
	ans = N - (mx + 1);
}
int main() {
	input();

	sol();
	printf("%d\n", ans);

	return 0;
}