#pragma warning (disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 100000+4
using namespace std;
/*
	�������� knapsack ���� 

	1. dp�迭�� �ǹ� 
		dp[i][w] = i��° ������ �־��� ��, �賶�� ���� ������ w�� �� v�� �ִ�
	2. dp ��ȭ�� 
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
	} // ó�� init

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