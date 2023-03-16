#pragma warning (disable : 4996)

#include <cstdio>
#include <vector>

using namespace std;
int n, m;
int parent[500001];

int getParent(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x > y) parent[x] = parent[y];
	else parent[y] = parent[x];
}

int main() {
	bool flag = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= m; i++) {
		int start, end;

		scanf("%d %d", &start, &end);

		if (getParent(start) != getParent(end)) {
			unionParent(start, end);
		}
		else {
			printf("%d\n", i);
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		puts("0");
	}
	return 0;
}