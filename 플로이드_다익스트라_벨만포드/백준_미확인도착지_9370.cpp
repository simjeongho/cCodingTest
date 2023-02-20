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
int T; //�׽�Ʈ ���̽� ��
int n, m, t; // ������ ���� ������ �ĺ��� ����
int s, g, h; // ������ , ������ ���� Ȯ���� �� ���
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
		//����� ����
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
		// �� ū �Ŷ� ��(��θ� �������Ƿ�)
	for (int i = 0; i < dests.size(); i++) {
		dests[i].cost = dist[dests[i].node];
	}
	dijkstra(cmp); // g/h�� �� ū �� �������� dijkstra�� �� ��

	for (auto a : dests) {
		if (a.cost == cmpdist + dist[a.node]) {
			printf("%d ", a.node);
		} // �ΰ��� ���� �Ͱ� ���ٸ� ���� ���̴�.
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