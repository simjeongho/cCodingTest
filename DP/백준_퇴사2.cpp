#pragma warning (disable : 4996)
/*
	N�� 1500000 �� ������ �����Ƿ� O(N^2)���δ� Ǯ�� ���Ѵ�. 
	O(N)�̳� O(NlogN)���� Ǯ����Ѵ�. 
*/
#include <cstdio>
#include <algorithm>
#define MAX 1500000+4
using namespace std;
int N;
int value[MAX];
int days[MAX];
int dp[MAX + 1000];
int ans;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &days[i], &value[i]);
		dp[i] = max(dp[i], dp[i - 1]);
		dp[i + days[i]] = max(dp[i + days[i]], dp[i] + value[i]);
		ans = max(ans, dp[i + days[i]]);
	}	

	/*for (int i = 0; i <= N + 1; i++) {
		printf("%d ", dp[i]);
	}*/
	printf("%d\n", dp[N] < dp[N + 1] ? dp[N + 1] : dp[N]);
	return 0;
}