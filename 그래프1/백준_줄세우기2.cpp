#pragma warning (disable:4996)

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define MAX 32002
int N, M;
int InDegree[MAX];
vector<int> AL[MAX]; //인접 리스트 adjacent list

int main() {
	scanf("%d %d", &N, &M);
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", & a, & b);
		AL[a].push_back(b);// 방향성이 있으므로 하나만 추가해주면 된다. 
		// AL[b].push_back(a) // 방향성이 없다면 다음과 같이 두 개 다 해야한다. 
		InDegree[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (InDegree[i] == 0) q.push(i);
	}
	if (q.size() == 0) return 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop(); // 탐색하려는 노드
		printf("%d ", cur); // 출력
		for (int i = 0; i < AL[cur].size(); i++) {
			//간선 지우기
			int tmp = AL[cur][i];
			if (--InDegree[tmp] == 0) q.push(tmp);
		}
	}

	return 0;
}
