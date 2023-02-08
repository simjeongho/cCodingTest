#pragma warning (disable : 4996)

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 10002
using namespace std;
int T; // 테스트 케이스 수
int N;
int visited[MAX];
int parent[MAX];
int inDegree[MAX];
vector<int> v[MAX];
int u1, u2;
void input() {
	memset(visited, 0, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	memset(inDegree, 0, sizeof(inDegree));
	for (int i = 1; i <= MAX; i++) {
		v[i].clear();
	}
	scanf("%d", &N); // 노드의 수
	for (int i  = 0; i < N-1; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		parent[e] = s;
		v[s].push_back(e);
		inDegree[e]++;
	}
	scanf("%d %d", &u1, &u2);
}
queue<int> q;
void bfs(int s) {
	visited[s] = 1;
	q.push(s);
	while (q.size()) {
		int cur = q.front(); q.pop();
		for (auto next : v[cur]) {
			if (!visited[next]) {
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
		}
	}
}

void sol() {
	int start = 0;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			start = i;
		}
	}
	bfs(start); // 각 노드의 depth를 구한다. 
	
	if (visited[u1] < visited[u2]) swap(u1, u2); //항상 u1이 더 아래 보장
	while (visited[u1] != visited[u2]) {
		u1 = parent[u1]; // 부모로 이동
	} // 같은 층 시작

	while (u1 != u2) {
		u1 = parent[u1];
		u2 = parent[u2]; // 한칸 씩 이동
	}
	printf("%d\n", u1);
}

int main() {
	scanf("%d", &T);
	for(int i=0; i< T; i++){
		input();
		sol();
	}
}