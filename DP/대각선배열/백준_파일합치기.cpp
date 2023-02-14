#pragma warning (disable : 4996)

#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 502
#define INF 0x3f3f3f3f
using namespace std;
int T;
int K;
int files[MAX];
int sums[MAX];
int dp[MAX][MAX]; // i ~j의 최솟 값 
void input() {
	memset(dp, 0, sizeof(dp));
	memset(sums, 0, sizeof(sums));
	scanf("%d", &K);
	for (int i = 1; i <= K; i++) {
		scanf("%d", &files[i]);
		sums[i] = sums[i - 1] + files[i];// 누적합 배열 만들어준다.
	}
}

void sol() {
	
	for (int i = 1; i <= K; i++) {
		dp[i][i] = 0;
		dp[i][i + 1] = files[i] + files[i + 1];
	}
	int temp = 1;
	for (int j = 2; j < K; j++) {
		for (int i = 1; i <= K; i++) {
			if (i + j <= K) {
				int temp = 0;
				dp[i][i+j] = INF;
				for (int k = i; k < i+j; k++) {
					dp[i][i+j] = min(dp[i][i+j], dp[i][k] + dp[k + 1][i+j]);
				}
				dp[i][i + j] += sums[i+j] - sums[i-1];
			}
		}
	}
	
}
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		input();
		sol();

		printf("%d\n", dp[1][K]);
	}
	return 0;
}