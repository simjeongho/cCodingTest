#pragma warning (disable : 4996)

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long 
using namespace std;
struct node {
	int start;
	int end;
	int cost;

	bool const operator < (const node& ref) const {
		return this->cost < ref.cost;
	}
};
int N; // ���� ����
int M; // �� ���ø� �����ϴ� ���̺�
int K; // K���� ������
int parent[1001];
vector<node> v;
ll ans;
//���̺��� ����Ǿ� �ִ� ���ÿ��� �����Ұ� �ݵ�� �ϳ��� �����ؾ��Ѵ�. 
int getParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = getParent(parent[x]);
	}
}
void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x > y) parent[x] = parent[y];
	else parent[y] = parent[x];
}
void input() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < K; i++) {
		int temp;
		scanf("%d", &temp);
		parent[temp] = 0;
	} // 0�� root 

	for (int i = 0; i < M; i++) {
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);
		v.push_back({ s, e, c });
	}
}

void sol() {

	sort(v.begin(), v.end());

	for (auto a : v) {
		if (getParent(a.start) != getParent(a.end)) {
			unionParent(a.start, a.end);
			ans += a.cost;
		}
	}
	printf("%lld\n", ans);

}
int main() {
	input();
	sol();
	return 0;
}