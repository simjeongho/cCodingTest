#pragma warning (disable : 4996)

#include <cstdio>
#include <cstring>
using namespace std;

int T; // �׽�Ʈ ���̽� Ƚ��
int N; // ���� ����
int coins[22]; // ���� ������ 20 +2
int goal; // �ִ� ����
int dp[22][10000 + 4];

void sol() {
	for (int j = 1; j <= goal; j++) {
		if (j % coins[1] == 0) dp[1][j] = 1;
	}// ù ��° �� �ʱ�ȭ
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= goal; j++) {
			if (j < coins[i]) dp[i][j] = dp[i - 1][j];
			else {
				for (int k = j % coins[i]; k <= j; k += coins[i]) {
					dp[i][j] += dp[i-1][k];
				}
				if (j % coins[i]==0) dp[i][j]++;
			}
		}
	}
	return;
}
int main() {

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int i = 0; i < 22; i++) {
			coins[i] = 0;
		} //���� ���� �ʱ�ȭ
		memset(dp, 0, sizeof(dp)); // dp�迭 �ʱ�ȭ 
		for (int i = 1; i <= N; i++) {
			scanf("%d", &coins[i]);
		}
		scanf("%d", &goal); // �������ϴ� �ݾ� 

		sol();

		/*for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= goal; j++) {
				printf("%d ", dp[i][j]);
			}
			printf("\n");
		}*/
		printf("%d\n", dp[N][goal]);
	}
	return 0;
}