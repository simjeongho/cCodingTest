#pragma warning (disable :4996)

/*
	�Է�
	���� N��
	������ M�� V�� ������ �ִ�. 
	������ K�� ������ �ְ� ���濡 ���� �� �ִ� �ִ� ���� C��. ������ �ִ� ����
	knapsack ���� - DP
	�迭�� �����Ѵ�. 
	���δ� ������ ���� 
	���δ� ������ ������ �ش��Ѵ�. 

	�� ������ ������ ���� ���԰� �Ѱ� ���Ա��� ������ �� ���� ���Կ� ���� ���� �� �ִ� ���� ���� ��ġ�� �κ� �����ط� ���´�. 

	1. ���� ����ϴ� ������ ���԰� ���� ����ϴ� ���Ժ��� ū ���
		- ���� �� ����. 
		value[i][j] = value[i-1][j]
	2. ���� ����ϴ� ������ ���԰� ���� ����ϴ� ���Ժ��� �۾� �賶�� ������ ���� �� �ִ� ���?
		- ���� �� �ִ�. 
		1. �ȳִ� ��찡 �� ���� ���
		value[i][j] = value[i-1][j]
		2. �ִ� ���� �� ���� ���
		value[i][j] = val + value[i-1][j-wi];
		---
		value[i][j] = max(value[i-1][j] , val + value[i-1][j-wi])


		Ǯ��
		-> ������ ������ ���� ������ asc ����
		-> ���� ���Կ� asc ����
		-> ������ ������ 
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long 
int N, K;
vector<pair<int, int>> jewel;
vector<int> bp;
priority_queue<int> pq;
ll ans;
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) return true;
	else return false;
}
void input() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		int weight, val;
		scanf("%d %d", &weight, &val);
		jewel.push_back({ weight, val });
	}
	for (int j = 0; j < K; j++) {
		int wei;
		scanf("%d", &wei);
		bp.push_back(wei);
	}
}
void sol() {
	sort(jewel.begin(), jewel.end(), cmp);
	sort(bp.begin(), bp.end()); // �ΰ� ����
	
	int i = 0;
	for (int j = 0; j < K; j++) {
		while (i < jewel.size() && jewel[i].first <= bp[j] ) {
			pq.push(jewel[i].second);
			i++;
		}

		if (pq.empty()) continue;
		else { 
			ans += pq.top();
			pq.pop();
		}
	}
	printf("%lld\n", ans);
}
int main() {
	input();
	sol();

	return 0;
}