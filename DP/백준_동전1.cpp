#pragma warning (disable:4996)

#include <cstdio>
#include <algorithm>
#include <vector>
/*
	n �ִ� 100 
	k �ִ� 10000

	dp[i][j] = i��° ������ �־��� �� j�� ������ ���� ������ ����� ��
	��ⷯ ������ ���� for���� ���� ����ȭ�ؾ��Ѵ�. 

	�޸� ������ 4MB��
	dp[100][10000]�� 4byte * 100 * 10000 = 4000000 = 4000KB = 4MB�̹Ƿ� ������ �Ѵ´�. 
	������ ����ϴ� ���� 2���� �ʿ��� 

*/
using namespace std;

int n;
int k;
int dp2[2][10000 + 2];
vector<int> v;

void sol() {
	for (int i = 0; i <= k; i++) {
		if (i == 0) dp2[0][i] = 1;
		else {
			if (i % v[0] == 0) {
				dp2[0][i] = 1;
			}
			else {
				dp2[0][i] = 0;
			}
		}
	}
	int cnt = 0;
	while (cnt < n - 1) {
		for (int j = 0; j <= k; j++) {
			if (j < v[cnt+1]) {
				dp2[1][j] = dp2[0][j];
			}
			else {
				for (int k = j % v[cnt+1]; k <= j; k += v[cnt+1]) {
					dp2[1][j] += dp2[0][k];
				}
			}
		}
		for (int j = 0; j <= k; j++) {
			dp2[0][j] = dp2[1][j]; // �ű��.
			dp2[1][j] = 0;
		}
		dp2[1][1] = 1;
		cnt++;
	}

	printf("%d\n", dp2[0][k]);
}
int main() {

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	sol();

	return 0;
}