#include <iostream>
#include <string>

#define MAX 4004
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
	
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (ans < dp[i][j]) ans = dp[i][j];
			}
		}
	}

	/*for (int i = 0; i <= len1; i++) {
		for (int j = 0; j < len2; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();

	sol();

	cout << ans << "\n";
	return 0;
}