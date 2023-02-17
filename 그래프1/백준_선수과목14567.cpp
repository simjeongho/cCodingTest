#pragma warning (disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1001
using namespace std;
int N, M;

int result[MAX];
vector<int> AL[MAX];
int inDegree[MAX];
queue<int> q;
void input() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		inDegree[b]++; //b가 당하는 화살표가 늘어난다.
		AL[a].push_back(b); // 단방향 그래프
	}
}

void topologySort() {
	for (int i = 1; i <= N; i++) {
		if (!inDegree[i]) {
			q.push(i); // inDegree가 없다면 q에 넣는다.
		}
	}
	while (q.size()) {
		int curr = q.front(); q.pop();
		for (int next : AL[curr]) {
			inDegree[next]--;
			if (!inDegree[next]) {
				result[next] = max(result[next], result[curr] + 1);
				q.push(next);
			}
		}
	}
}
int main() {

	input();
	topologySort();

	for (int i = 1; i <= N; i++) {
		printf("%d ", result[i] + 1);
	}

	return 0;
}