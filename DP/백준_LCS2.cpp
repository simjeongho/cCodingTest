#include <iostream>
#include <string>
#include <algorithm>

#define MAX 1004
using namespace std;
string s1, s2;
int len1, len2;
int dp[MAX][MAX];
int ans;
void input() {
	cin >> s1 >> s2;
	len1 = s1.length();
	len2 = s2.length();
}
string tmp;
void traceBack(int y, int x) {
	if (y < 0 || x < 0) {
		return;
	}
	if (dp[y][x - 1] == dp[y][x]) {
		traceBack(y, x - 1);
	}
	else if (dp[y - 1][x] == dp[y][x]) {
		traceBack(y - 1, x);
	}
	else {
		tmp = s1[x-1] + tmp;
		traceBack(y - 1, x - 1);
	}
}
void sol() {
	for (int i = 1; i <= len2; i++) {
		for (int j = 1; j <= len1; j++) {
			if (s1[j - 1] == s2[i - 1]) {
				dp[i][j] =dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	traceBack(len2, len1);
	cout << dp[len2][len1] << "\n";
	cout << tmp << "\n";
}

int main() {
	input();
	sol();

	return 0;
}
