#pragma warning (disable : 4996)
#define INF 0x3f3f3f3f
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
struct n_t {
	int node;
	int cost;
	inline bool operator < (const n_t &ref) const {
		return this->cost > ref.cost;
	}
}; // 구조체 정의 
int N, E; // 정점의 개수와 간선의 개수
vector<n_t> AL[801]; // 인접 리스트
int dist[801]; // 거리배열
priority_queue<n_t> q1;
priority_queue<n_t> q2;
int u, v;
ll ans;
int midCost;
ll midU, midV , mid2U,mid2V; // 1번의 다익스트라가 끝난 후 반드시 지나야하는 두 정점 중 작은 값
void input() {
	scanf("%d %d", &N, &E);
	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		AL[a].push_back({ b,c });
		AL[b].push_back({ a,c }); // 방향성이 없다. 
	}
	scanf("%d %d", &u, &v); // 반드시 지나야하는 u v
}
void sol() {
	for (int i = 0; i < 801; i++) {
		dist[i] = INF;
	} // 무한대로 초기화
	dist[1] = 0;
	q1.push({ 1, 0 });
	while (q1.size()) {
		auto curr = q1.top(); q1.pop();
		for (auto next : AL[curr.node]) {
			int cost = dist[curr.node] + next.cost;
			if (dist[next.node] > cost) {
				dist[next.node] = cost;
				q1.push({ next.node, cost });
			}
		}
	} // 다익스트라 1번 
	// u,v 둘 다 무한대라면 불가능하다. u]
	midU = dist[u];
	midV = dist[v];
	for (int i = 0; i < 801; i++) {
		dist[i] = INF;
	} // 무한대로 초기화
	dist[u] = 0;
	q2.push({ u, 0 });
	while (q2.size()) {
		auto curr = q2.top(); q2.pop();
		for (auto next : AL[curr.node]) {
			int cost = dist[curr.node] + next.cost;
			if (dist[next.node] > cost) {
				dist[next.node] = cost;
				q2.push({ next.node, cost });
			}
		}
	} // 다익스트라 2번 u -> v;
	mid2V = dist[v];
	mid2U = dist[v];
	//for (int i = 0; i < 801; i++) {
	//	dist[i] = INF;
	//} // 무한대로 초기화
	//dist[v] = 0;
	//q2.push({ v, 0 });
	//while (q2.size()) {
	//	auto curr = q2.top(); q2.pop();
	//	for (auto next : AL[curr.node]) {
	//		int cost = dist[curr.node] + next.cost;
	//		if (dist[next.node] > cost) {
	//			dist[next.node] = cost;
	//			q2.push({ next.node, cost });
	//		}
	//	}
	//} // 다익스트라 3번 v-> u;
	//mid2U = dist[u];
	for (int i = 0; i < 801; i++) {
		dist[i] = INF;
	} // 무한대로 초기화
	dist[N] = 0;
	q2.push({ N, 0 });
	while (q2.size()) {
		auto curr = q2.top(); q2.pop();
		for (auto next : AL[curr.node]) {
			int cost = dist[curr.node] + next.cost;
			if (dist[next.node] > cost) {
				dist[next.node] = cost;
				q2.push({ next.node, cost });
			}
		}
	} // 다익스트라 4번 N->u,v
	ll tmp1 = midU + mid2V + dist[v];
	ll tmp2 = midV + mid2U + dist[u];
	ans = min(tmp1, tmp2);
	if (ans >= INF) {
		puts("-1\n");
	}
	else {
		printf("%lld", ans);
	}
	
}
int main() {
	input();
	sol();
	return 0;
}