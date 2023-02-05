#pragma warning (disable :4996)

/*
	입력
	보석 N개
	보석은 M과 V를 가지고 있다. 
	가방을 K개 가지고 있고 가방에 담을 수 있는 최대 무겐 C다. 보석의 최대 가격
	knapsack 문제 - DP
	배열을 선언한다. 
	가로는 물건의 개수 
	세로는 물건의 무개에 해당한다. 

	각 물건의 개수에 대해 무게가 한계 무게까지 증가할 때 현재 무게에 대해 넣을 수 있는 가장 높은 가치를 부분 최적해로 놓는다. 

	1. 현재 고려하는 물건의 무게가 현재 고려하는 무게보다 큰 경우
		- 넣을 수 없다. 
		value[i][j] = value[i-1][j]
	2. 현재 고려하는 물건의 무게가 현재 고려하는 무게보다 작아 배낭에 물건을 넣을 수 있는 경우?
		- 넣을 수 있다. 
		1. 안넣는 경우가 더 나은 경우
		value[i][j] = value[i-1][j]
		2. 넣는 것이 더 나은 경우
		value[i][j] = val + value[i-1][j-wi];
		---
		value[i][j] = max(value[i-1][j] , val + value[i-1][j-wi])


		풀이
		-> 가방을 가능한 무게 순으로 asc 정렬
		-> 보석 무게에 asc 정렬
		-> 가능한 보석을 
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
	sort(bp.begin(), bp.end()); // 두개 정렬
	
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