#pragma warning (disable:4996)

#include <cstdio>
#include <map>
using namespace std;
#define MAX 1003
#define INF 1000000000
#define ll long long
int N, M;
ll ans=1;
int Ns[MAX];
int Ms[MAX];
bool isLimit;
int gcd(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
void input() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &Ns[i]);
	}
	scanf("%d", &M);
	for (int j = 0; j < M; j++) {
		scanf("%d", &Ms[j]);
	}
}

void sol() {
	//Ns의 숫자들을 하나씩 소인수분해 해보기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int gc = gcd(Ns[i], Ms[j]);

			Ns[i] /= gc;
			Ms[j] /= gc;
			ans *= gc;
			if (ans >= INF) {
				ans %= INF;
				isLimit = 1;
			}
		}
	}
	if (isLimit) {
		printf("%09lld", ans);
	}
	else {
		printf("%lld", ans);
	}
}
int main() {
	input();
	sol();

	return 0;
}