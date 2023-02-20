#pragma warning (disable : 4996)

#include <cstdio>
#include <algorithm>
#define MAX 201
using namespace std;
int N, M; // N은 도시 수 M은 여행계획에 속한 도시들의 수
int parent[MAX];
int ans[1001];
int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int l, int r) {
	l = getParent(l);
	r = getParent(r);
	if (l < r) parent[r] = parent[l];
	else parent[l] = parent[r];
}
void sol() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			scanf("%d", &tmp);
			if (tmp == 1) {
				unionParent(i, j);
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		scanf("%d", &ans[i]);
		ans[i] = getParent(ans[i]);
		//printf("ans[%d] : %d\n", i, ans[i]);
	}
}
int main() {

	sol();

	for (int i = 1; i < M; i++) {
		if (ans[i] != ans[i + 1]) {
			//printf("ans[%d] : %d ans[%d]%d\n", i,ans[i], i+1, ans[i + 1]);
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}