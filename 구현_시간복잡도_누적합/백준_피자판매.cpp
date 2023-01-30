#pragma warning (disable : 4996)
/*
	백준 - 두 배열의 합 문제와 비슷한 문제
	map을 이용해 자동으로 정렬해주는 것을 이용한다. 
	피자는 고리 형태를 띄고 있으므로 for문을 다 돌아줘야한다. 하지만 가지치기가 가능하다. 
*/
#include <cstdio>
#include <map>
#define ll long long
#define MAX 2004
using namespace std;
ll T;
int m, n;
int ns[MAX];
int ms[MAX];
ll ans;
ll totalN;
ll totalM;
map <ll, ll> pizza;
void input() {
	scanf("%d", &T);
	scanf("%d %d", &m, &n);

	for (int i = 1; i <= m; i++) {
		scanf("%d", &ms[i]);
		ms[i + m] = ms[i];
		totalM += ms[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ns[i]);
		ns[i + n] = ns[i];
		totalN += ns[i];
	}
}

void sol() {
	

	for (int i = 1; i <= m; i++) {
		ll sumM = 0;
		for (int j = i; j < m + i-1; j++) {
			sumM += ms[j];
			if (sumM > T) break;
			if (sumM == T) ans++;
			pizza[sumM]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		ll sumN = 0;
		for (int j = i; j < n + i-1; j++) {
			sumN += ns[j];
			if (sumN > T) break;
			if (sumN == T) {
				ans++;
				break;
			}
			ans += pizza[T - sumN];
		}
	}
	pizza[totalM] = 1;
	ans += pizza[T - totalN];
	if (totalN == T) ans++;
	if (totalM == T) ans++;
	printf("%lld\n", ans);
}
int main() {
	input();
	sol();
	return 0;
}