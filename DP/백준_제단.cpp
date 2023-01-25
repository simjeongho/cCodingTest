#pragma warning (disable : 4996)
/*
	������ �����غ��� ������ ����. 
	0��° : 0������
	1��° : 0 1 ����
	2��° : 0 1 2 ���� 
	k��° : 0 1 2 ... k ���� 

	-1�� ���� ������ ���İ� �����̴�. 
	-1�� ��쿡 ������ �� ���� �ϳ��� �������ٴ� ���� ������ �׳� ���� ��°�� �������� �ϴ�.
	������ ���̰� �������� ���� �� ������ �����Ѵ�. 
	1. ���� ������ ���̺��� ���� ���
	2. ���� ������ ���̿� ���� ���
	3. ���� ������ ���̺��� ���� ���

	10000 * 4byte = 40000 byte = 40KByte * 10000 = 400,000KByte = 400MB
	�޸� �ʰ��� ���� �ȴ�. ���� ���̿� �ش��ϴ� DP�迭�� ����� �ٿ�����Ѵ�. 

	�޸� ������ 256MB�̹Ƿ� 10000 * 4byte = 40KB * 5000 = 200MB //�޸� ���� �����Ѵ�. 
	c++������ pageFault���� ������ ���� �޸𸮸� Ž���ϴ� ���� ȿ���� ����. ���� ���̿� �ش��ϴ� �κ��� ���̷� ������ش�. 
*/
#include <cstdio>
#include <algorithm>
#define MAX 10000+2
#define MOD 1000000007
using namespace std;
int N; // ������ ���� ��
int inputs[MAX];
int dp[MAX][5001]; // ���� �� ���� 
int ans;
void makeDP() {
	//�ʱ� �� ����
	dp[0][0] = 1; // �� ���� ���� 0�� 1�� �ʱ�ȭ�Ѵ�. 
	for (int i = 1; i < N; i++) {
		if (inputs[i] == -1) {
			//���� ���ϸ��� �����̾��ٸ� ������ ���� ������ ���̱��� ��� ä���ش�.
			for (int j = 0; j <= min(i, N - i - 1); j++) {
				//i�� ���� �����ؾ��Ѵ�.
				if (j == 0) {
					dp[i][j] += dp[i - 1][j];
					dp[i][j] %= MOD;
					dp[i][j] += dp[i - 1][j + 1];
					dp[i][j] %= MOD;
				}
				else {
					 // �ƴ϶�� �� ���� ��츦 ��� �������־�� �Ѵ�.
					dp[i][j] += dp[i - 1][j];
					dp[i][j] %= MOD;
					dp[i][j] += dp[i - 1][j + 1];
					dp[i][j] %= MOD;
					dp[i][j] += dp[i - 1][j - 1];
					dp[i][j] %= MOD;
				}
			}
		}
		//���� �Է¹��� ���̰� -1�� �ƴϾ��ٸ� 
		else {
			//�ش��ϴ� ��, ���� ��ġ�� �迭 ĭ���ٰ� ���� �־�����Ѵ�.
			if (inputs[i] == 0) {
				dp[i][inputs[i]] += dp[i - 1][inputs[i]];
				dp[i][inputs[i]] %= MOD;
				dp[i][inputs[i]] += dp[i - 1][inputs[i] + 1];
				dp[i][inputs[i]] %= MOD;
			}
			else {
				dp[i][inputs[i]] += dp[i - 1][inputs[i]];
				dp[i][inputs[i]] %= MOD;
				dp[i][inputs[i]] += dp[i - 1][inputs[i] + 1];
				dp[i][inputs[i]] %= MOD;
				dp[i][inputs[i]] += dp[i - 1][inputs[i] - 1];
				dp[i][inputs[i]] %= MOD;
			}
		}
	}
	ans = dp[N - 1][0] % MOD;
}

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &inputs[i]); // ��ǲ �Է�
		//���� �Է¹��� ���̰� min(i, N - i - 1)���� ũ�ٸ� �ٷ� 0�� �����Ѵ�.
		if (inputs[i] > min(i, N - i - 1)) {
			printf("%d\n", 0);
			return 0;
		}
	}
	makeDP();
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j <= min(i, N - 1 - i); j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}*/
	printf("%d\n", ans);
	return 0;
}