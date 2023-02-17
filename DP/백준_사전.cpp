/*
	��� ���ڿ��� N���� a�� M���� z�� �̷�����ִ�. �ٸ� ���� x
	���ĺ� ������� ���ϵǾ� �ִ�. 

	N�� M�� �־����� �� �Կ����� �������� K��° ���ڿ��� �������� ���ϴ� ���α׷�

	map�� �ִ´�. 

	�� ���ڿ��� ����  : 2 2 
	�� ���ڿ��� ������ 2����ŭ ���� ����� ��
	4C2
	total ���ϰ� 

	dp[i][j] = a i���� z j���� ������ �� �ִ� ����� ��

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
		ll needToCMP = dp[a_cnt - 1][z_cnt];//�̰ź��� ������ a��� ũ�� z���

		if (a_cnt == 0) {
			printf("z");
			z_cnt--;
		} // 0�� ��츦 ���� ���� �Ű� ������Ѵ�.
		else if (z_cnt == 0) {
			printf("a");
			a_cnt--;
		} // 0�� ��츦 ���� ���� �Ű������Ѵ�.
		else if (K <= needToCMP) {
			printf("a");
			a_cnt--;
		} // ���� dp[i-1][j]���� �۴ٸ� a�� ����Ѵ�.
		else {
			printf("z");
			K -= needToCMP;
			z_cnt--;
		}// ���� dp[i-1][j]���� ũ�ٸ� z�� ����Ѵ�.
	}
}

int main() {
	input();
	sol();
	return 0;
}
