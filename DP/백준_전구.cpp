/*
	DP의 가장 중요한 점
	1. dp 배열이 의미하는 것 
	2. 점화식

	이 문제에서 dp[start][end]는 start에서 end까지 하나의 전구 색으로 만들 때 가장 적은 횟수
	
	분할 정복을 이용해야한다.
	dp(1,n)을 구간 1에서 n까지의 전구의 색을 바꾸는 횟수의 최솟값이라고 하고
	dp(1,k) + dp(k+1, n)으로 분할하여 최솟값을 찾는다.

	여기서의 핵심 아이디어는 
	dp[1][4] = min(dp[1][1] + dp[2][4] + (전구[1]!=전구[2]), dp[1][2] + dp[3][4] + (전구[2] != 전구[3]) , dp[1][3] + dp[4][4] + (전구[3] != 전구[4])) 이다. 
*/

#pragma warning (disable : 4996)

#include <cstdio>
#include <algorithm>
#define BULBMAX 202
#define INF 0x3f3f3f3f
using namespace std;
int N, K;

int dp[BULBMAX][BULBMAX];
int bulb[BULBMAX];

int sol(int start, int end) {
	if (start == end) return 0;
	
	if (dp[start][end]) return dp[start][end];
	// 바로 옆인 경우
	if (start-1 == end)return (bulb[start] != bulb[end]);

	int tmp = INF; //최솟 값을 구하므로 무한대로 초기화해준다.
	for (int i = start; i < end; i++) {
		tmp = min(tmp, sol(start, i) + sol(i+1, end) + (bulb[i] != bulb[i+1]));
	}
	return dp[start][end] = tmp;
}
int main() {
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &bulb[i]);
	} // 전구 입력 

	printf("%d\n", sol(1, N));

	/*printf("\n");
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}