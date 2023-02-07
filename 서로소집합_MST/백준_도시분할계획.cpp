#pragma warning (disable : 4996)
/*
	��� �������ε� �ٴ� �� �ִ�. ->  ����� ���̴�. 
	�� ���� �и��� ������ ������ �����Ѵ�. 

	1. �ּ� ���� Ʈ���� �����.
	2. ���� Ʈ���� ���Ե� ���� �� ���� ū ������ �����Ѵ�.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
#define MAX 100004
using namespace std;
struct edge {
	int start;
	int end;
	int cost;
	inline bool const operator < (const edge& ref) const {
		if (this->cost < ref.cost) return true;
		else return false;
	} // ������ �����ε�
};
ll parent[MAX];
int N, M;
ll ans;
int cnt;
vector<edge> Edges;
void input() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);
		Edges.push_back({ s,e,c });
	}
}
int getParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = getParent(parent[x]); // ��� ����
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
	sort(Edges.begin(), Edges.end()); // ����
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		// �θ� �迭 �ʱ�ȭ
	}
	for (int i = 0; i < M; i++) {
		if (!isCycle(Edges[i].start, Edges[i].end)) {
			unionParent(Edges[i].start, Edges[i].end); // ����Ŭ�� ���ٸ� unionParent
			if (cnt == N - 2) break;
			cnt++;
			ans += Edges[i].cost;
		}
	}

	printf("%lld\n",ans);
}
int main() {
	input();
	kruscal();
	return 0;
}