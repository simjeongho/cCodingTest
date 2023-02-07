#pragma warning (disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long 
#define MAX 1002

using namespace std;
struct edge {
	int start;
	int end;
	ll cost;
	inline bool const operator < (const edge& ref) const {
		if (this->cost < ref.cost) return true;
		else return false;
	}
};
int N; //�༺ ��
ll dist[MAX][MAX];
int parent[MAX];
vector<edge> Edges;
ll ans;
int cnt;
void input() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)  {
		for (int j = 1; j <= N; j++) {
			scanf("%lld", &dist[i][j]);
			if (j > i) {
				Edges.push_back({ i, j, dist[i][j] });
			} // �밢�� ���� push
		}
	}
}

int getParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getParent(parent[x]);
}
void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
}
bool isCycle(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x == y) return true;
	else return false;
}

void kruscal() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	} // �θ� �迭 �ʱ�ȭ
	sort(Edges.begin(), Edges.end()); // ���� ����
	for (int i = 0; i < Edges.size(); i++) {
		if (!isCycle(Edges[i].start, Edges[i].end)) {
			unionParent(Edges[i].start, Edges[i].end);
			ans += Edges[i].cost;
			cnt++; 
			if (cnt == N - 1) break;
		}
	}
	printf("%lld\n", ans);
}
int main() {
	input();
	kruscal();
}