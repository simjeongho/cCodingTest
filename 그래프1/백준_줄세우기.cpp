#pragma warning (disable : 4996)
/*
	DAG 의 특성을 가진다. 
	방향성은 존재하고 싸이클은 존재하지 않는다. 

	위상정렬로써 문제를 생각할 수 있다. 
	-> 결과가 한 개가 아니다. 
*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define MAX 32002
int N,M;

vector<int> compare[MAX];
int inDegree[MAX];
int result[MAX];
void topologySort(int n) {
	
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}
	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			return;
		}
		int x = q.front();
		q.pop(); // inDegree가 0인 노드부터 시작
		result[i] = x;
		for (int i = 0; i < compare[x].size(); i++) {
			inDegree[compare[x][i]] --;
			if (inDegree[compare[x][i]] == 0) {
				q.push(compare[x][i]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		printf("%d ", result[i]);
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		compare[tmp1].push_back(tmp2);
		inDegree[tmp2]++;
	}
	topologySort(N);
}
