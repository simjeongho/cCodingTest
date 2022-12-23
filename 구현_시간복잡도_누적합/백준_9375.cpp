#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int T; //테스트 케이스 수
int N; //의상 수
string name;
string kind;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		map<string, int> _map;
		for (int i = 1; i <= N; i++) {
			cin >> name >> kind;
			_map[kind]++;
		}
		long long ret = 1;
		for (auto c : _map) {
			ret *= ((long long)c.second + 1);
		}
		ret--;
		cout << ret << "\n";
	}
}