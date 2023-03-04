#pragma warning (disable : 4996)

#include <cstdio>
#include <algorithm>
using namespace std;
int T, N;
int cards[1002];

int dp[1002][1002][2];

int turn(int start, int end, bool my) {
	int& ret = dp[start][end][my];
	if (ret != -1) return ret;
	if (start == end) {
		if (my) {
			return ret = cards[start];
		}
		else {
			return ret = 0;
		}
	}
	if (my) {
		return ret = max(turn(start + 1, end, 0) + cards[start], turn(start, end - 1, 0) + cards[end]);
	}
	else {
		return ret = min(turn(start + 1, end, 1), turn(start, end - 1, 1));
	}
}
int main() {
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		memset(cards, 0, sizeof(cards));
		memset(dp, -1, sizeof(dp));
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &cards[i]);
		}
		printf("%d\n", turn(0, N - 1, 1));
	}
	return 0;
}