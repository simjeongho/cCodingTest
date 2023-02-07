#pragma warning (disable : 4996)

#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
#define MAX 10004
using namespace std;
struct edge {
	int start;
	int end;
	int cost;
	inline bool const operator < (const edge &ref) const {
		if (this->cost < ref.cost) return true;
		else return false;
	}
};
int V, E;
vector<edge> Edges;
ll cost;
ll parent[MAX]; // 부모 배열 
int getParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getParent(parent[x]);
}
void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x < y) parent[y] = x;
	else parent[x] = y;
}

bool isCycle(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x == y) return true;
	else return false;
}
void input() {
	scanf("%d %d", &V, &E);

	for (int i = 0; i < E; i++) {
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);
		Edges.push_back({ s,e,c }); // 간선 정보 저장
	}
}

void kruscal() {
	sort(Edges.begin(), Edges.end());

	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	} // 부모배열 초기화

	for (int i = 0; i < E; i++) {
		//간선 개수 만큼
		if (!isCycle(Edges[i].start, Edges[i].end)) {
			// cycle이 없다면 union
			unionParent(Edges[i].start, Edges[i].end);
			cost += Edges[i].cost;
		}
	}
	printf("%lld\n", cost);
}
int main() {
	input(); // 입력
	kruscal();
	return 0;
}