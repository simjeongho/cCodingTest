#pragma warning (disable : 4996)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define ll long long
string combi[102][102];
int n, m;
string sum(string a, string b) {
	string res = "";
	if (a.size() > b.size()) {
		while (a.size() != b.size()) {
			b = '0' + b;
		}
	}
	else {
		while (a.size() != b.size()) {
			a = '0' + a;
		}
	}
	int sum = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		sum += a[i] - '0';
		sum += b[i] - '0';
		res = to_string(sum % 10) + res;
		sum /= 10;
	}
	if (sum) res = to_string(sum) + res;
	return res;
}

string makeTree(int n, int m) {
	combi[0][0] = "1";
	combi[1][0] = "1"; combi[1][1] = "1";
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j==i) combi[i][j] = "1";
			else {
				combi[i][j] = sum(combi[i - 1][j - 1], combi[i - 1][j]);
			}
		}
	}
	return combi[n][m];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	makeTree(n , m);
	cout << combi[n][m] << "\n";
	return 0;
}