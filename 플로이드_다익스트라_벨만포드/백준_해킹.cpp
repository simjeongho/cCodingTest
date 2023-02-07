#pragma warning (disable : 4996)
#define ll long long
#define INF 0x3f3f3f3f
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct n_t {
	int node;
	int cost;
	inline bool const operator < (const n_t& ref) const{
		return this->cost > ref.cost;
	} // 연산자 오버로딩 
};
int T; // 테스트 케이스 수
int n, d, c;
vector<n_t> AL[10002];
ll dist[10002];
void sol() {
	priority_queue<n_t> pq;
	ll mx = 0;
	int cnt = 0;
	scanf("%d %d %d", &n, &d, &c);
	for (int i = 0; i < d; i++) {
		int a, b, s;
		scanf("%d %d %d", &a, &b, &s);
		AL[b].push_back({ a,s }); // 인접리스트 형성
	}
	for (int i = 0; i < 10002; i++) {
		dist[i] = INF;
	} // dist 배열 초기화
	dist[c] = 0;
	pq.push({ c, 0 });
	while (pq.size()) {
		n_t curr = pq.top(); pq.pop();
		for (auto next : AL[curr.node]) {
			int cost = dist[curr.node] + next.cost;
			if (dist[next.node] > cost) {
				dist[next.node] = cost; // 거리 업데이트
				pq.push({ next.node, cost });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i] != INF) {
			cnt++;
			mx = max(mx, dist[i]);
		}
	}
	printf("%d %lld\n", cnt, mx);
}
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		for (int i = 0; i < 10002; i++) {
			AL[i].clear();
		} // 인접 리스트 초기화
		sol();
	}
}