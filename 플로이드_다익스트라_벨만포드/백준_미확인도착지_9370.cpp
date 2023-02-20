#pragma warning (disable : 4996)

#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <functional>
#define MAX 2001
#define INF 0x3f3f3f3f
using namespace std;
int T; //테스트 케이스 수
int n, m, t; // 교차로 도로 목적지 후보의 개수
int s, g, h; // 시작점 , 지나간 것이 확실한 두 경로
int nextdist[MAX];
int dist[MAX];
struct n_t {
	int node;
	int cost;
	inline bool const operator < (const n_t& ref) const {
		return this->cost > ref.cost;
	}
};
vector<n_t> AL[MAX];
vector<n_t> dests;
bool cmp(n_t a, n_t b) {
	return a.node < b.node;
}
void input() {
	scanf("%d %d %d", &n, &m, &t);
	scanf("%d %d %d", &s, &g, &h);
	for (int i = 1; i <= n; i++) {
		AL[i].clear();
	}
	dests.clear();
	for (int i = 1; i <= m; i++) {
		int a, b, d;
		scanf("%d %d %d", &a, &b, &d);
		//양방향 도로
		AL[a].push_back({ b,d });
		AL[b].push_back({ a,d });
	}
	for (int i = 0; i < t; i++) {
		int x;
		scanf("%d", &x);
		dests.push_back({x, INF});
	}
	sort(dests.begin(), dests.end(), cmp);
}
void dijkstra(int start) {
	priority_queue<n_t> pq;
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[start] = 0;
	pq.push({ start, 0 });
	while (pq.size()) {
		n_t curr = pq.top(); pq.pop();
		if (dist[curr.node] < curr.cost) continue;
		for (n_t next : AL[curr.node]) {
			int cost = dist[curr.node] + next.cost;
			if (dist[next.node] > cost) {
				dist[next.node] = cost;
				pq.push({ next.node , cost });
			}
		}
	}
}
void sol() {
	int gdist = dist[g];
	int hdist = dist[h];
	int cmpdist = 0;
	int cmp = 0;
	if (gdist < hdist) {
		cmpdist = hdist;
		cmp = h;
	}
	else {
		cmpdist = gdist;
		cmp = g;
	}
		// 더 큰 거랑 비교(경로를 지났으므로)
	for (int i = 0; i < dests.size(); i++) {
		dests[i].cost = dist[dests[i].node];
	}
	dijkstra(cmp); // g/h중 더 큰 걸 시작으로 dijkstra한 번 더

	for (auto a : dests) {
		if (a.cost == cmpdist + dist[a.node]) {
			printf("%d ", a.node);
		} // 두개를 더한 것과 같다면 지난 것이다.
	}
	printf("\n");
}
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		input();
		dijkstra(s);
		sol();
	}

	/*for (int i = 1; i <= n; i++) {
		printf("%d ", dist[i]);
	}
	printf("\n");
	for (int i = 1; i <= n; i++) {
		printf("%d ", dest[i]);
	}*/

	return 0;
}