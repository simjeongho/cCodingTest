#pragma warning (disable : 4996)

#include <cstdio>
#include <vector>
#include <queue>
#define MAX 1001
#define BUSMAX 100001
#define INF 0x3f3f3f3f
using namespace std;

int n, m;
struct n_t {
	int node;
	int cost;

	inline bool const operator < (const n_t& ref) const {
		return this->cost > ref.cost;
	}
};
int dist[MAX];
vector<n_t> AL[MAX];
int prevPath[MAX];
vector<int> path;
int root, leaf;
void input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);
		AL[s].push_back({ e,c }); //인접리스트 생성
	}
}

void dijkstra(int root) {
	priority_queue<n_t> pq;
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	} // 무한대로 초기화
	
	dist[root] = 0;
	pq.push({ root, 0 });
	while (pq.size()) {
		n_t curr = pq.top(); pq.pop();
		if (dist[curr.node] < curr.cost) continue;
		for (n_t next : AL[curr.node]) {
			int cost = dist[curr.node] + next.cost;
			if (dist[next.node] > cost) {
				dist[next.node] = cost;
				prevPath[next.node] = curr.node;
				pq.push({ next.node, cost });
			}
		}
	}
}
int cnt = 1;
int main() {

	input();
	scanf("%d %d", &root, &leaf);
	dijkstra(root);
	printf("distance --\n");
	for (int i = 1; i <= n; i++) {
		printf("%d ", dist[i]);
	}
	printf("\n");
	printf("prevPath --\n");
	for (int i = 1; i <= n; i++) {
		printf("%d ", prevPath[i]);
	}
	printf("\n");
	int idx = leaf;
	path.push_back(leaf);
	while (1) {
		if (prevPath[idx] == 0) break;
		cnt++;
		path.push_back(prevPath[idx]);
		idx = prevPath[idx];
	}
	printf("%d\n%d\n",dist[leaf], cnt);
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
	return 0;
}