#pragma warning (disable : 4996)

#include <cstdio>
#define MAX 131072
#define SIZE_TR 262144
#define ll long long
using namespace std;
int offset = 1;
int N , M;
ll Tree[SIZE_TR];
int origin[MAX];
void input() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp % 2) {
			origin[i] = 1; // 홀수라면 1을 집어넣는다.
		}
	}
}
void initTree() {
	while (offset < N) offset *= 2;

	for (int i = 0; i < N; i++)  Tree[offset + i] = origin[i];

	for (int i = offset - 1; i > 0; i--) Tree[i] = Tree[i * 2] + Tree[i * 2 + 1];
}

void update(int idx, int val) {
	idx += offset;
	if (val % 2) Tree[idx] = 1;
	else Tree[idx] = 0;

	while (idx) {
		idx /= 2;
		Tree[idx] = Tree[idx * 2] + Tree[idx * 2 + 1];
	}
}

int query(int from, int to) {
	int ans = 0;
	from += offset; to += offset;
	while (from <= to) {
		if (from % 2) ans += Tree[from++];
		if ((to % 2) == 0) ans += Tree[to--];
		from /= 2; to /= 2;
	}
	return ans;
}
int main() {
	input();
	initTree();

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 1) {
			int a, x;
			scanf("%d %d", &a, &x);
			update(a-1, x);
		}
		else if (cmd == 2) {
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%d\n", r - l - query(l-1, r-1) + 1);
		}
		else {
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%d\n", query(l-1, r-1));
		}
	}

	return 0;
}