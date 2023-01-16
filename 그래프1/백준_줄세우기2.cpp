#pragma warning (disable:4996)

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define MAX 32002
int N, M;
int InDegree[MAX];
vector<int> AL[MAX]; //���� ����Ʈ adjacent list

int main() {
	scanf("%d %d", &N, &M);
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", & a, & b);
		AL[a].push_back(b);// ���⼺�� �����Ƿ� �ϳ��� �߰����ָ� �ȴ�. 
		// AL[b].push_back(a) // ���⼺�� ���ٸ� ������ ���� �� �� �� �ؾ��Ѵ�. 
		InDegree[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (InDegree[i] == 0) q.push(i);
	}
	if (q.size() == 0) return 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop(); // Ž���Ϸ��� ���
		printf("%d ", cur); // ���
		for (int i = 0; i < AL[cur].size(); i++) {
			//���� �����
			int tmp = AL[cur][i];
			if (--InDegree[tmp] == 0) q.push(tmp);
		}
	}

	return 0;
}
