#pragma warning (disable : 4996)

#include <cstdio>
#include <algorithm>
#include <unordered_map>
#define ll long long
using namespace std;

int N; // 배열의 크기
int NN;
ll A[4001]; //4KB
ll B[4001]; // 4KB
ll C[4001]; // 4KB
ll D[4001]; // 4KB
ll ans;
//unordered_map<ll, int> ab;
//unordered_map<ll, int> cd;
ll AB[16000000 + 4];
ll CD[16000000 + 4];
void input() {
	scanf("%d", &N);
	NN = N * N;
	for (int i = 0; i < N; i++) {
		scanf("%lld %lld %lld %lld", 
			&A[i] , &B[i], &C[i], &D[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			/*ab[A[i] + B[j]]++;
			cd[C[i] + D[j]]++;*/
			AB[i * N + j] = A[i] + B[j];
			CD[i * N + j] = C[i] + D[j];
		}
	} // 4000 * 4000
}

void sol() {
	sort(AB, AB + NN);
	sort(CD, CD + NN);

	for (int i = 0; i < NN; i++) {
		ll cnt = upper_bound(CD, CD + NN, -AB[i]) - lower_bound(CD, CD + NN, - AB[i]);
		ans += cnt;
	}
	/*for (auto a : ab) {
		ans = ans + ab[a.first] * cd[-a.first];
	}*/
	printf("%lld\n", ans);
}
int main() {
	input();
	sol();
	return 0;
}