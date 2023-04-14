#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;
map<string, int> mp;
map<string, int> ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		mp[temp]++;
	}
	for (int j = 0; j < M; j++) {
		string temp2;
		cin >> temp2;
		mp[temp2]++;
		if (mp[temp2] == 2) {
			ans[temp2]++;
		}
	}
	cout << ans.size() << "\n";
	for (auto a : ans) {
		cout << a.first << "\n";
	}
	return 0;
}