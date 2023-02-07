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
	} // ������ �����ε� 
};
int T; // �׽�Ʈ ���̽� ��
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
		AL[b].push_back({ a,s }); // ��������Ʈ ����
	}
	for (int i = 0; i < 10002; i++) {
		dist[i] = INF;
	} // dist �迭 �ʱ�ȭ
	dist[c] = 0;
	pq.push({ c, 0 });
	while (pq.size()) {
		n_t curr = pq.top(); pq.pop();
		for (auto next : AL[curr.node]) {
			int cost = dist[curr.node] + next.cost;
			if (dist[next.node] > cost) {
				dist[next.node] = cost; // �Ÿ� ������Ʈ
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
		} // ���� ����Ʈ �ʱ�ȭ
		sol();
	}
}