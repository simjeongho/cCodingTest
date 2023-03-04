#pragma warning (disable : 4996)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[104][104][104];
string s1, s2, s3;
int sz1, sz2, sz3;
void input() {
	cin >> s1 >> s2 >> s3;
	sz1 = s1.size();
	sz2 = s2.size();
	sz3 = s3.size();
}

void sol() {
	for (int i = 1; i <= sz1; i++) {
		for (int j = 1; j <= sz2; j++) {
			for (int k = 1; k <= sz3; k++) {
				if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
					//모두 같으면 
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else {
					dp[i][j][k] = max(dp[i][j][k - 1], max(dp[i - 1][j][k], dp[i][j - 1][k]));
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	sol();
	cout << dp[sz1][sz2][sz3] << "\n";
	return 0;
}