#pragma warning (disable : 4996)

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N , M; // 노드의 N개 노드의 쌍 M
vector<int> v[50000];
int parent[50001];
int visited[50000 + 2];
void sol(int x, int y) {
	queue<int> q;
	visited[1] = 1;
	q.push(1);
	while (q.size()) {
		int curr = q.front(); q.pop();
		for (int a : v[curr]) {
			if (!visited[a]) {
				visited[a] = visited[curr] + 1;
				parent[a] = curr;
				q.push(a);
			}
		}
	}
	int hx = visited[x];
	int hy = visited[y];
	if (hx >= hy) {
		while (hx != hy) {
			x = parent[x];
			hx--;
		}
		while (x != y) {
			x = parent[x];
			y = parent[y];
		}
		printf("%d\n", x);
	}
	else {
		while (hx != hy) {
			y = parent[y];
			hy--;
		}
		while (x != y) {
			x = parent[x];
			y = parent[y];
		}
		printf("%d\n", x);
	}
}
void input() {
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		//if (a > b) swap(a, b);
		v[a].push_back(b); // b는 a에 연결되어 있다. 
		v[b].push_back(a);// b도 a에 연결되어 있다. 
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		sol(x, y);
	}
}
int main() {
	input();
	return 0;
}