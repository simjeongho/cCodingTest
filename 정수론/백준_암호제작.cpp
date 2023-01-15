#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define MAX 1000000
/*
	�����佺�׳׽��� ä�� �̿��ؼ� �Ҽ� ����Ʈ�� ������ ���� 
	�˻縦 �Ѵ�.
*/
int K;
string p;
bool isNotPrime[MAX + 3];
int ans=0x3f3f3f3f;
void input() {
	cin >> p >> K;
}
//�����佺�׳׽��� ä
void makeList() {
	for (int i = 2; i * i <= MAX; i++) {
		if (isNotPrime[i])continue;
		for (int j = i+i; j <= MAX; j += i) {
			isNotPrime[j] = true;
		}
	}
}
void sol() {	
	for (int i = 2; i < K; i++) {
		int ret = 0;
		if (isNotPrime[i]) continue;
		for (int j = 0; j < p.size(); j++) {
			ret = (ret * 10 + p[j] - '0') % i;
		}
		if (ret == 0) {
			ans = i;
			cout << "BAD " << ans << "\n";
			return;
		}
	}
	if (ans < K) cout << "BAD " << ans << "\n";
	else cout << "GOOD\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	makeList();
	sol();
	return 0;
}