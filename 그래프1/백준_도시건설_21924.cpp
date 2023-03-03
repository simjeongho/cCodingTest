#pragma warning  (disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 100000
#define ll long long
using namespace std;
int N, M;
int parent[100000 + 1];
ll total = 0;
struct edge {
	int start;
	int end;
	int cost;
	inline bool const operator < (edge& ref) const {
		return this->cost < ref.cost;
	}
};
vector<edge>Edge;

int getParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x < y) parent[y] = parent[x];
	else parent[x] = parent[y];
}

bool isCycle(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x == y) return true;
	else return false;
}
void input() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);
		Edge.push_back({ s,e,c });
		total += c;
	}
}
int main() {
	ll ans = 0;
	int edgeCnt = 0;
	input();

	sort(Edge.begin(), Edge.end());

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		if (!isCycle(Edge[i].start, Edge[i].end)) {
			unionParent(Edge[i].start, Edge[i].end);
			ans += Edge[i].cost;
			edgeCnt++;
		}
	}


	if (edgeCnt != N-1) {
		puts("-1");
		return 0;
	}
	printf("%lld", total - ans);

	return 0;
}