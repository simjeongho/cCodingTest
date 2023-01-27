#pragma warning (disable: 4996)
/*
	백준 - 게임개발
	위상 정렬 문제인 거 같다. 
	위상 정렬 문제에서는 inDegree배열이 중요하다. 

	하나의 노드를 탐색하면서 inDegree를 없앤다. 
	모두 없앤 후 탐색하며 inDegree가 0인 노드들은 누적합 배열을 통해 구해준다. 
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 502
using namespace std;
int N;
vector <int> v[MAX]; // 인접 행렬
int dist[MAX];
int inDegree[MAX];
int result[MAX];
void input() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int tmp = 0;
		for (int j = 0; j <= N; j++) {
			if (j == 0) {
				scanf("%d", &tmp);
				dist[i] = tmp;
			}
			else {
				scanf("%d", &tmp);
				if (tmp == -1) break;
				v[tmp].push_back(i);
				inDegree[i]++;
			}
		}
	}

	/*for (int i = 1; i <= N; i++) {
		printf("%d ", dist[i]);
	}
	printf("\n");*/
}
void topologySort() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) { 
			q.push(i); 
			result[i] = dist[i];
		} // 만약 inDegree가 0인 것이 있다면 q에 넣어준다.
	}
	if (q.empty()) return;

	while (q.size()) {
		int x = q.front(); q.pop();
		for (int a : v[x]) {
			inDegree[a]--;
			result[a] = max(result[a], result[x] + dist[a]);
			if (inDegree[a] == 0) {
				q.push(a); // q에 집어넣는다.
			}
		}
	}
}
int main() {
	input();
	topologySort();

	for (int i = 1; i <= N; i++) {
		printf("%d\n", result[i]);
	}
	
	return 0;
}