#pragma warning (disable : 4996)

#include <cstdio>
#include <queue>
#define MAX 100000
#define ll long long
using namespace std;
int N;
ll cards[MAX + 1];
ll ans;
priority_queue<ll, vector<ll>, greater<>> pq;
void input() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &cards[i]);
		pq.push(cards[i]);
	}
}

void sol() {
	/*if (N == 1) {
		return;
	}*/
	while (pq.size()) {
		ll first = pq.top(); pq.pop();
		ll second = 0;
		if (pq.size()) {
			second = pq.top(); pq.pop();
		}
		first += second;
		printf("first : %lld\n", first);
		ans += first;
		if (pq.size()) {
			pq.push(first);
		}
	}
}
int main() {
	input();
	sol();
	printf("%lld\n", ans);
	return 0;
}