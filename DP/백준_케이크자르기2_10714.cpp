#pragma warning (disable : 4996)

#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

int N;
ll cakes[2020];
ll dp[2020][2020];
ll ioi(int start, int end);
ll joi(int start, int end);
int goLeft(int x) {
	return (x + N - 1) % N;
}
int goRight(int x) {
	return (x + 1) % N;
}


void input() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &cakes[i]);
	}
}
int main() {
	ll ans = 0;
	input();
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++) {
		ans = max(ans, cakes[i] + ioi(i, i));
	}

	printf("%lld\n", ans);
	return 0;
}

ll ioi(int start, int end) {
	//1. ���� ������ 
	if (goRight(end) == start) return 0;
	//2. ioi�� �� ū���� ������ 
	if (cakes[goRight(end)] < cakes[goLeft(start)]) {
		return joi(goLeft(start), end);
	}
	else return joi(start, goRight(end));
}
ll joi(int start, int end) {
	//1. ������ �� ��� 
	if (goRight(end) == start) return dp[start][end] = 0;
	//2. ������ �� ���
	if (dp[start][end] != -1) return dp[start][end];
	//3. �� ū ��츦 �����Ѵ�.
	ll L = ioi(goLeft(start), end) + cakes[goLeft(start)];
	ll R = ioi(start, goRight(end)) + cakes[goRight(end)];
	return dp[start][end] = max(L, R);
}