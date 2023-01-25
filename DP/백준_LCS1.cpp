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
void sol() {
	for (int i = 1; i <= len2; i++) {
		for (int j = 1; j <= len1; j++) {
			if (s1[j - 1] == s2[i - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[len2][len1] << "\n";
}

int main() {
	input();
	sol();

	return 0;
}