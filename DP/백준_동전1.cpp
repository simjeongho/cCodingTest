#pragma warning (disable:4996)

#include <cstdio>
#include <algorithm>
#include <vector>
/*
	n 최대 100 
	k 최대 10000

	dp[i][j] = i번째 물건을 넣었을 때 j의 무게의 합이 가능한 경우의 수
	모듈러 연산을 통해 for문을 돌며 최적화해야한다. 

	메모리 제한이 4MB임
	dp[100][10000]는 4byte * 100 * 10000 = 4000000 = 4000KB = 4MB이므로 제한이 넘는다. 
	어차피 계산하는 것은 2열만 필요함 

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
			dp2[0][j] = dp2[1][j]; // 옮긴다.
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