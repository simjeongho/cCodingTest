#pragma warning (disable : 4996)
/*
	DAG �� Ư���� ������. 
	���⼺�� �����ϰ� ����Ŭ�� �������� �ʴ´�. 

	�������ķν� ������ ������ �� �ִ�. 
	-> ����� �� ���� �ƴϴ�. 
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
		q.pop(); // inDegree�� 0�� ������ ����
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
