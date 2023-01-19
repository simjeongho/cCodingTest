#pragma warning (disable : 4996)

#include <cstdio>

using namespace std;
#define MAX 502
int n;
int triangle[MAX][MAX];
int ans;
void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			scanf("%d", &triangle[i][j]);
		}
	}
}

void sol() {
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			//처음 시작
			if (j == 0) {
				triangle[i][j] += triangle[i - 1][j];
			}
			else if (j == i) {
				triangle[i][j] += triangle[i - 1][j - 1];
			}
			else {
				triangle[i - 1][j - 1] < triangle[i - 1][j] ? triangle[i][j] += triangle[i - 1][j] : triangle[i][j] += triangle[i - 1][j - 1];
			}
		}
	}

	for (int k = 0; k < n; k++) {
		if (ans < triangle[n - 1][k]) {
			ans = triangle[n - 1][k];
		}
	}
}
int main() {
	input();
	sol();

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			printf("%d ", triangle[i][j]);
		}
		printf("\n");
	}*/

	printf("%d\n", ans);
	return 0;
}