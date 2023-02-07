#pragma warning (disable : 4996)
/*
	어느 방향으로든 다닐 수 있다. ->  양방향 길이다. 
	두 개의 분리된 마을로 분할을 진행한다. 

	1. 최소 신장 트리를 만든다.
	2. 신장 트리에 포함된 간선 중 가장 큰 간선을 삭제한다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
#define MAX 100004
using namespace std;
struct edge {
	int start;
	int end;
	int cost;
	inline bool const operator < (const edge& ref) const {
		if (this->cost < ref.cost) return true;
		else return false;
	} // 연산자 오버로딩
};
ll parent[MAX];
int N, M;
ll ans;
int cnt;
vector<edge> Edges;
void input() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);
		Edges.push_back({ s,e,c });
	}
}
int getParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getParent(parent[x]); // 경로 압축
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
void kruscal() {
	sort(Edges.begin(), Edges.end()); // 정렬
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		// 부모 배열 초기화
	}
	for (int i = 0; i < M; i++) {
		if (!isCycle(Edges[i].start, Edges[i].end)) {
			unionParent(Edges[i].start, Edges[i].end); // 사이클이 없다면 unionParent
			if (cnt == N - 2) break;
			cnt++;
			ans += Edges[i].cost;
		}
	}

	printf("%lld\n",ans);
}
int main() {
	input();
	kruscal();
	return 0;
}