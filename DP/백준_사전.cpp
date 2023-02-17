/*
	모든 문자열은 N개의 a와 M개의 z로 이루어져있다. 다른 문자 x
	알파벳 순서대로 수록되어 있다. 

	N과 M이 주어졌을 때 규완이의 사전에서 K번째 문자열이 무엇인지 구하는 프로그램

	map에 넣는다. 

	총 문자열의 개수  : 2 2 
	총 문자열의 수에서 2개만큼 고르는 경우의 수
	4C2
	total 구하고 

	dp[i][j] = a i개와 z j개로 구성할 수 있는 경우의 수

*/
#pragma warning(disable:4996)

#include <cstdio>
#define ll long long
#define INF 1000000000
#define MAX 101
int N, M, K;

ll dp[MAX][MAX];

void input() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i <= M; i++) {
		dp[0][i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (dp[i - 1][j] + dp[i][j - 1] > INF) {
				dp[i][j] = INF;
			}
			else {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
}

void sol() {
	int a_cnt = N;
	int z_cnt = M;

	if (dp[N][M] < K) {
		puts("-1");
		return;
	}
	for (int i = 0; i < N + M; i++) {
		ll needToCMP = dp[a_cnt - 1][z_cnt];//이거보다 작으면 a출력 크면 z출력

		if (a_cnt == 0) {
			printf("z");
			z_cnt--;
		} // 0인 경우를 제일 먼저 신경 써줘야한다.
		else if (z_cnt == 0) {
			printf("a");
			a_cnt--;
		} // 0인 경우를 제일 먼저 신경써줘야한다.
		else if (K <= needToCMP) {
			printf("a");
			a_cnt--;
		} // 만약 dp[i-1][j]보다 작다면 a를 출력한다.
		else {
			printf("z");
			K -= needToCMP;
			z_cnt--;
		}// 만약 dp[i-1][j]보다 크다면 z를 출력한다.
	}
}

int main() {
	input();
	sol();
	return 0;
}
