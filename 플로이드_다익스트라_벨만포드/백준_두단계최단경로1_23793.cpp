#pragma warning (disable : 4996)

#include <cstdio>
#include <vector>
#include <queue>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int N, M;
int X, Y, Z;
struct n_t {
	int node;
	ll cost;
	inline bool const operator < (const n_t& ref) const {
		return this->cost > ref.cost;
	}
};
vector<n_t> AL[100001];
ll dist[100001];
bool visited[100001];
void input() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		AL[start].push_back({ end, cost }); // 단방향 그래프
	}
	scanf("%d %d %d", &X, &Y, &Z);
}

ll dijkstra(int start, int end) {
	priority_queue<n_t> pq;
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	dist[start] = 0;
	pq.push({ start, 0 });
	while (pq.size()) {
		n_t curr = pq.top(); pq.pop();
		if (dist[curr.node] < curr.cost) continue;
		for (n_t next : AL[curr.node]) {
			ll cost = dist[curr.node] + next.cost;
			if (cost < dist[next.node]) {
				dist[next.node] = cost;
				pq.push({ next.node , cost });
			}
		}
	}
	return dist[end];
}

ll dijkstra2(int start, int end) {
	priority_queue<n_t> pq;
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	dist[start] = 0;
	pq.push({ start, 0 });
	while (pq.size()) {
		n_t curr = pq.top(); pq.pop();
		if (dist[curr.node] < curr.cost) continue;
		for (n_t next : AL[curr.node]) {
			ll cost = dist[curr.node] + next.cost;
			if (next.node != Y && cost < dist[next.node]) {
				dist[next.node] = cost;
				pq.push({ next.node , cost });
			}
		}
	}
	return dist[end];
}
int main() {
	input();

	ll mid1 = dijkstra(X, Y);
	ll mid2 = dijkstra(Y, Z);

	ll mid3 = dijkstra2(X, Z);

	//printf("%lld %lld %lld\n", mid1, mid2, mid3);
	if (mid1 >= INF || mid2 >= INF) {
		printf("-1 ");
	}
	else printf("%lld ", mid1 + mid2);
	if (mid3 >= INF) {
		printf("-1\n");
	}
	else printf("%lld\n", mid3);
}