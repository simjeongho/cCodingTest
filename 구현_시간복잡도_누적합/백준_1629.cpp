#include <iostream>
#include <algorithm>
using namespace std;

long long a,b,c;
long long go(long long a, long long b) {
	if (b == 1) return a % c;
	long long ret = go(a, b / 2);
	ret = (ret * ret) % c;
	if (b % 2)ret = (ret * a) % c;//홀수라면 한 번 더 곱해준다.
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b >> c;
	/*int res = 0; 
	res = a % c;
	for (int i = 1; i < b; i++) {
		res = res * a % c;
	}
	cout << res<<"\n";*/
	cout << go(a, b) << "\n";
	return 0;
}
