#pragma warning (disable:4996)
/*
	Ǯ��
	���� �������� ����� ���� ��� �����ش�. 
	map�� �̿��ؼ� �ڵ� ������ �ǵ��� ���ش�.
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
	} // �Է¹޴´�. 
}
void sol() {
	
	for (int i = 1; i <= n; i++) {
		int sumA = 0;
		for (int j = i; j <= n; j++) {
			sumA += ns[j];
			amap[sumA]++;
		}
	} // n���� �Է����� �� ������ �������� ���� map�ۼ�

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