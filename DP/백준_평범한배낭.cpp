#pragma warning (disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 100000+4
using namespace std;
/*
	전형적인 knapsack 문제 

	1. dp배열의 의미 
		dp[i][w] = i번째 물건을 넣었을 때, 배낭의 무게 제한이 w일 때 v의 최댓값
	2. dp 점화식 
		dp[i][w] = max(dp[i-1][w] , dp[i-1][w-wi] + vi)
*/
int N, K;
int dp[102][MAX];
vector <pair<int, int>> v;

void sol() {
	for (int i = 0; i <= K; i++) {
		if (v[0].first <= i) {
			dp[1][i] = v[0].second;
		}
	} // 처음 init

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (v[i - 1].first > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1].first] + v[i-1].second);
			}
		}
	}

	/*for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}*/
	printf("%d\n", dp[N][K]);

}
int main() {
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back({ a,b });
	}

	sol();

	return 0;
}