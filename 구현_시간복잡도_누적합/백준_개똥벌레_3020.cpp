#pragma warning(disable : 4996)

#include <cstdio>
#include <algorithm>
#define ll long long
#define MAX 100002
#define INF 0x3f3f3f3f
using namespace std;
int N, H; // N은 동굴 미터 H는 동굴 높이
ll top[MAX];
ll bottom[MAX];
void input() {
	scanf("%d %d", &N, &H);

	for (int i = 0; i < N; i++) {
		ll temp;
		scanf("%lld", &temp);
		if ((i % 2) == 0) {
			bottom[temp]++;
		}
		else {
			top[H - temp + 1] ++;
		}
	}
}

void sol() {
	for (int i = 1; i <= H; i++) {
		top[i] += top[i - 1];
		bottom[H - i + 1] += bottom[H - i + 2];
	}//누적합 배열 만든다.

	ll ans = INF;
	int cnt = 0;
	for (int i = 1; i <= H; i++) {
		if (top[i] + bottom[i] < ans) {
			cnt = 1;
			ans = top[i] + bottom[i];
		}
		else if (top[i] + bottom[i] == ans) {
			cnt++;
		}
	}

	printf("%d %d\n", ans, cnt);
}
int main() {
	input();
	sol();
	return 0;
}