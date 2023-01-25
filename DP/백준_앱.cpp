#pragma warning (disable:4996)

#include <cstdio>
#include <algorithm>
#define COUNTMAX 102
#define COSTMAX 10000+4
#define INF 0x3f3f3f3f
using namespace std;
int N, M;
int memory[COUNTMAX];
int cost[COUNTMAX];
int sum;
int DP[101][COSTMAX];// i번째 앱까지 확인했을 때 j의 비용으로 얻을 수 있는 최대의 메모리
void input() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &memory[i]);
	} // 메모리 값들 입력
	for (int j = 1; j <= N;j++) {
		scanf("%d", &cost[j]);
		sum += cost[j];
	}// 최소 비용 입력 
}
int ans = INF;
int sol() {
	bool flag = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j >= cost[i]) DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - cost[i]] + memory[i]);
			else DP[i][j] = DP[i - 1][j];
			if (DP[i][j] >= M) {
				ans = min(ans, j);
			}
		}
	}

	/*for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= sum; j++) {
			printf("%d ", DP[i][j]);
		}
		printf("\n");
	}*/
	return ans;
}

int main() {

	input();

	sol();

	printf("%d\n", ans);

	return 0;
}