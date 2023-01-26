/*
	DP�� ���� �߿��� ��
	1. dp �迭�� �ǹ��ϴ� �� 
	2. ��ȭ��

	�� �������� dp[start][end]�� start���� end���� �ϳ��� ���� ������ ���� �� ���� ���� Ƚ��
	
	���� ������ �̿��ؾ��Ѵ�.
	dp(1,n)�� ���� 1���� n������ ������ ���� �ٲٴ� Ƚ���� �ּڰ��̶�� �ϰ�
	dp(1,k) + dp(k+1, n)���� �����Ͽ� �ּڰ��� ã�´�.

	���⼭�� �ٽ� ���̵��� 
	dp[1][4] = min(dp[1][1] + dp[2][4] + (����[1]!=����[2]), dp[1][2] + dp[3][4] + (����[2] != ����[3]) , dp[1][3] + dp[4][4] + (����[3] != ����[4])) �̴�. 
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
	// �ٷ� ���� ���
	if (start-1 == end)return (bulb[start] != bulb[end]);

	int tmp = INF; //�ּ� ���� ���ϹǷ� ���Ѵ�� �ʱ�ȭ���ش�.
	for (int i = start; i < end; i++) {
		tmp = min(tmp, sol(start, i) + sol(i+1, end) + (bulb[i] != bulb[i+1]));
	}
	return dp[start][end] = tmp;
}
int main() {
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &bulb[i]);
	} // ���� �Է� 

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