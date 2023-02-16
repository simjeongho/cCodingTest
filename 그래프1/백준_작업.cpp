#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
vector<int> AL[10001];
vector<int>From[10001];
int cost[10001];
int inDegree[10001];
queue<int> q;
int result[10001];
void input() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int cnt;
		scanf("%d", &cost[i]);
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++) {
			int prev;
			scanf("%d", &prev); // ����Ǵ� �۾��� �Է¹޴´�.
			inDegree[i]++; //����Ǿ���ϴ� ���� ����
			AL[prev].push_back(i); // ����Ǵ� �ʺ��� ȭ��ǥ�� �����Ѵ�.
		}
	}
}

void topologySort() {
	//inDegree�� 0�� ������ ���
	for (int i = 1; i <= N; i++) {

		if (!inDegree[i]) {
			q.push(i);
		}
		result[i] = cost[i];
	}
	while (q.size()) {
		int curr = q.front(); q.pop();
		for (int destinate : AL[curr]) {
			inDegree[destinate]--;
			result[destinate] = max(result[destinate], result[curr] + cost[destinate]);
			if (!inDegree[destinate]) {
				//printf("%d ", destinate);
				q.push(destinate);
			}
		}
	}
}
int main() {
	input();

	
	/*printf("\n");
	for (int i = 1; i <= N; i++) {
		printf("%d ", cost[i]);
	}*/
	topologySort();
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, result[i]);
	}
	printf("%d\n", ans);
	return 0;
}