
#pragma warning (disable :4996)

#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>
#define ll long long 
using namespace std;

int K, N;
ll primeNum[101];
int cnt;
priority_queue<ll, vector<ll>, greater<ll>> pq;
map<ll, bool> mp;
void input() {
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++) {
		scanf("%lld", &primeNum[i]);
	}
}

void sol() {
	for (int i = 0; i < K; i++) {
		mp[primeNum[i]] = 1; // 방문 표시
		pq.push(primeNum[i]); // pq에 값을 넣어준다.
	}
	ll mx = 0;
	while (cnt < N-1) {
		ll curr = pq.top(); pq.pop();
		cnt++;
		//printf("pq.top() : %d\n", -pq.top());
		for (int i = 0; i < K; i++) {
			ll next = curr * primeNum[i];
			if (mp.count(next)) continue;
			if (pq.size() > N) {
				if (mx <= next) continue;
			}
			//printf("curr * primeNum[%d] : %d\n", i, curr * primeNum[i]);
			mp[next] = true; // 방문 표시
			pq.push(next);
			mx = max(mx, next);
		}

	}
	printf("%lld\n", pq.top());
}
int main() {
	input();
	sol();

	return 0;
}