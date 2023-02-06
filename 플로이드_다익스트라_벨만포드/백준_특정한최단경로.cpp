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
}; // ����ü ���� 
int N, E; // ������ ������ ������ ����
vector<n_t> AL[801]; // ���� ����Ʈ
int dist[801]; // �Ÿ��迭
priority_queue<n_t> q1;
priority_queue<n_t> q2;
int u, v;
ll ans;
int midCost;
ll midU, midV , mid2U,mid2V; // 1���� ���ͽ�Ʈ�� ���� �� �ݵ�� �������ϴ� �� ���� �� ���� ��
void input() {
	scanf("%d %d", &N, &E);
	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		AL[a].push_back({ b,c });
		AL[b].push_back({ a,c }); // ���⼺�� ����. 
	}
	scanf("%d %d", &u, &v); // �ݵ�� �������ϴ� u v
}
void sol() {
	for (int i = 0; i < 801; i++) {
		dist[i] = INF;
	} // ���Ѵ�� �ʱ�ȭ
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
	} // ���ͽ�Ʈ�� 1�� 
	// u,v �� �� ���Ѵ��� �Ұ����ϴ�. u]
	midU = dist[u];
	midV = dist[v];
	for (int i = 0; i < 801; i++) {
		dist[i] = INF;
	} // ���Ѵ�� �ʱ�ȭ
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
	} // ���ͽ�Ʈ�� 2�� u -> v;
	mid2V = dist[v];
	mid2U = dist[v];
	//for (int i = 0; i < 801; i++) {
	//	dist[i] = INF;
	//} // ���Ѵ�� �ʱ�ȭ
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
	//} // ���ͽ�Ʈ�� 3�� v-> u;
	//mid2U = dist[u];
	for (int i = 0; i < 801; i++) {
		dist[i] = INF;
	} // ���Ѵ�� �ʱ�ȭ
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
	} // ���ͽ�Ʈ�� 4�� N->u,v
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