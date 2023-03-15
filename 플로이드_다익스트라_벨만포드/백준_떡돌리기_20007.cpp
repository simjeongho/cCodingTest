#pragma warning (disable : 4996)

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

struct n_t {
	int node;
	int cost;
	inline bool const operator < (const n_t& ref) const {
		return this->cost > ref.cost;
	}
};
int N, M, X, Y;
vector<n_t> AL[1001];
ll dist[1001];
int ans =0;
void dijkstra(int home) {
	priority_queue<n_t> pq;
	for (int i = 0; i < N; i++) {
		dist[i] = INF;
	}
	dist[home] = 0;
	pq.push({ home, 0 });

	while (pq.size()) {
		n_t curr = pq.top(); pq.pop();
		if (dist[curr.node] < curr.cost) continue;
		for (auto next : AL[curr.node]) {
			int cost = dist[curr.node] + next.cost;

			if (dist[next.node] > cost) {
				dist[next.node] = cost;
				pq.push({ next.node, cost });
			}
		}
	}
}
int main() {
	scanf("%d %d %d %d", &N, &M, &X, &Y);
	for (int i = 0; i < M; i++) {
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);
		AL[s].push_back({ e,c });
		AL[e].push_back({ s,c }); // 양방향 도로
	}
	dijkstra(Y);

	for (int i = 0; i < N; i++) {
		if (dist[i] * 2 > X) {
			puts("-1");
			return 0;
		}
	}

	sort(dist, dist + N);
	int start = 0;
	int end = 1;
	while (start < N && end < N) {
		ll sums = dist[end] * 2; //왕복 거리
		while (sums <= X && end < N) {
			end++;
			sums += dist[end] * 2;
		}
		start = end;
		ans++;
	}

	printf("%d\n", ans);
	return 0;
}