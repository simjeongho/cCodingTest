#pragma warning (disable:4996)
/*
	풀이
	각각 누적합의 경우의 수를 모두 구해준다. 
	map을 이용해서 자동 정렬이 되도록 해준다.
*/
#include <cstdio>
#include <map>
#define MAX 1002
#define ll long long
using namespace std;
int T;
int n,m;
int ns[MAX];
int ms[MAX];
ll ans;
map <ll, ll> amap;
void input() {
	scanf("%d %d", &T , &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ns[i]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &ms[i]);
	} // 입력받는다. 
}
void sol() {
	
	for (int i = 1; i <= n; i++) {
		int sumA = 0;
		for (int j = i; j <= n; j++) {
			sumA += ns[j];
			amap[sumA]++;
		}
	} // n들을 입력했을 때 가능한 누적합의 개수 map작성

	for (int i = 1; i <= m; i++) {
		int sumB = 0;
		for (int j = i; j <= m; j++) {
			sumB += ms[j];
			ans += amap[T - sumB];
		}
	}
	printf("%lld\n", ans);
}

int main() {
	input();
	sol();

	return 0;
}