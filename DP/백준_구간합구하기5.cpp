#pragma warning (disable : 4996)

#include <cstdio>
#define MAX 1028
using namespace std;

int N,M;
int nums[MAX][MAX];
int adds[MAX][MAX];
int x1, y1, x2, y2;

int sol(int y1, int x1, int y2, int x2) {
	int ans = 0;
	for (int i = y1; i <= y2; i++) {
		ans += adds[i][x2] - adds[i][x1-1];
	}
	return ans;
}
void input() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &nums[i][j]);
			adds[i][j] = adds[i][j - 1] + nums[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", adds[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n",sol(x1, y1, x2, y2));
	}
}
int main() {
	input();
	return 0;
}