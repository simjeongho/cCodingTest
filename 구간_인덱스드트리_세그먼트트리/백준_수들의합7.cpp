#pragma warning (disable : 4996)
#define ll long long
#define SIZE_TR 2097152
#define MAX 1048576
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
ll Tree[SIZE_TR];
int offset = 1;
void update(int idx, int val) {
	idx += offset -1;
	Tree[idx] = val;
	while (idx > 0) {
		idx /= 2;
		Tree[idx] = Tree[idx * 2] + Tree[idx * 2 + 1];
	}
}
ll query(int from, int to) {
	if (from > to) swap(from, to);
	ll ans = 0;
	from += offset-1; to += offset-1;
	while (from <= to) {
		if (from % 2) ans += Tree[from++];
		if ((to % 2) == 0) ans += Tree[to--];
		from /= 2; to /= 2;
	}
	printf("%lld\n", ans);
	return ans;
}
void sol() {
	scanf("%d %d", &N, &M);
	while (offset < N) offset *= 2;
	for (int i = 0; i < M; i++) {
		int q, f, s;
		scanf("%d %d %d", &q, &f, &s);
		if (q == 0) {
			query(f, s);
		}
		else {
			update(f, s);
		}
	}
}

int main() {
	sol();
	return 0;
}