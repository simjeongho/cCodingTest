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
int N; // 도시 개수
int M; // 두 도시를 연결하는 케이블
int K; // K개의 발전소
int parent[1001];
vector<node> v;
ll ans;
//케이블이 연결되어 있는 도시에는 발전소가 반드시 하나만 존재해야한다. 
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
	} // 0은 root 

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