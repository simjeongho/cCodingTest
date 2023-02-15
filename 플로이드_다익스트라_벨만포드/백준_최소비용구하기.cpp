#pragma warning(disable : 4996)

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
#define BUSMAX 100001
#define INF 0x3f3f3f3f
using namespace std;
int N , M;
int root, leaf;
struct city {
	int node;
	int cost;
	inline bool const operator < (const city& ref) const{
		return this->cost > ref.cost;
	}
};
vector<city> AL[MAX];
int dist[MAX];
void input() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);
		AL[s].push_back({ e,c }); // 단방향 그래프
	}
	//for (int i = 1; i <= N; i++) sort(AL[i].begin(), AL[i].end());
}
void dijkstra(int root) {

	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}// 무한대로 초기화
	priority_queue<city> pq;

	dist[root] = 0;
	pq.push({ root,0 });
	while (pq.size()) {
		city curr = pq.top(); pq.pop();
		if (dist[curr.node] < curr.cost) continue;
		for (city next : AL[curr.node]) {
			int cost = dist[curr.node] + next.cost;
			if (dist[next.node] > cost) {
				dist[next.node] = cost;
				pq.push({ next.node, cost });
			}
		}
	}
}

int main() {

	input();
	scanf("%d %d", &root, &leaf);
	dijkstra(root);

	printf("%d\n", dist[leaf]);

	return 0;
}