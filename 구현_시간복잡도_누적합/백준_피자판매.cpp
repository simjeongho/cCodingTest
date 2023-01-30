#pragma warning (disable : 4996)
/*
	���� - �� �迭�� �� ������ ����� ����
	map�� �̿��� �ڵ����� �������ִ� ���� �̿��Ѵ�. 
	���ڴ� �� ���¸� ��� �����Ƿ� for���� �� ��������Ѵ�. ������ ����ġ�Ⱑ �����ϴ�. 
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