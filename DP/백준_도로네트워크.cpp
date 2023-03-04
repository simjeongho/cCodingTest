/*
	sparse table을 유도한다. (K와 N이 크기 때문이다.)
*/
#pragma warning (disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define  MAX 100000
#define INF 0x3f3f3f3f
#define HEIGHT 21
using namespace std;
int N, K;
vector<pair<int, int>>AL[MAX + 2];
int parent[MAX][HEIGHT];
int depth[MAX];
int min_road[MAX][HEIGHT];
int max_road[MAX][HEIGHT];
queue<int> q;
void makeTree() {
	depth[1] = 1;
	q.push({ 1 });
	while (q.size()) {
		int curr = q.front(); q.pop();
		for (auto next : AL[curr]) {
			if (!depth[next.first]) {
				depth[next.first] = depth[curr] + 1;
				parent[next.first][0] = curr;
				min_road[next.first][0] = next.second;
				max_road[next.first][0] = next.second;
				q.push(next.first);
			}
		}
	}
}

void makeParent() {
	for (int k = 0; k < HEIGHT - 1; k++) {
		for (int x = 1; x <= N; x++) {
			if (parent[x][k] != 0) {
				parent[x][k + 1] = parent[parent[x][k]][k];
				max_road[x][k + 1] = max(max_road[x][k], max_road[parent[x][k]][k]);
				min_road[x][k + 1] = min(min_road[x][k], min_road[parent[x][k]][k]);
			}
		}
	}
}

void lca2(int l, int r) {
	if (depth[l] < depth[r]) swap(l, r);
	int diff = depth[l] - depth[r];
	int cnt = 0;
	int mn = INF, mx = 0;
	while (diff) {
		if (1 & diff) {
			mn = min(min_road[l][cnt], mn);
			mx = max(max_road[l][cnt], mx);
			l = parent[l][cnt];
		}
		cnt++;
		diff >>= 1;
	} // 둘의 depth를 맞춘다.
	//printf("afterl  : %d after r : %d\n", l, r);
	if (l != r) {
		for (int i = HEIGHT - 1; i >= 0; i--) {
			if (parent[l][i] != parent[r][i]) {
				mn = min(min_road[l][i], mn);
				mn = min(min_road[r][i], mn);
				mx = max(max_road[l][i], mx);
				mx = max(max_road[r][i], mx);
				l = parent[l][i];
				r = parent[r][i];
			}
		}
		if (min_road[l][0] != 0 && min_road[r][0] != 0) {
			mn = min(min_road[l][0], mn);
			mn = min(min_road[r][0], mn);
		}
		if (max_road[l][0] != 0 && max_road[r][0] != 0) {
			mx = max(max_road[l][0], mx);
			mx = max(max_road[r][0], mx);
		}
	}
	printf("%d %d\n", mn, mx);
}

void input() {
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		AL[a].push_back({ b,c });
		AL[b].push_back({ a,c }); // 인접리스트
	}

	scanf("%d", &K);
}
int main() {

	input();
	makeTree();
	makeParent();
	for (int i = 0; i < K; i++) {
		int d, e;
		scanf("%d %d", &d, &e);
		lca2(d, e);
	}

	return 0;
}