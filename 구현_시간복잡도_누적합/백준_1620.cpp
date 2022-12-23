#include <iostream>
#include <algorithm>
#include <string>
#include <map>
//Map을 사용한다.
//Map의 탐색 시간 복잡도는 logN
using namespace std;

int N; // 포켓몬 개수
int M; //맞춰야하는 문제의 개수
map<string, int> mp;
map<int, string> mp2;
string s;
string book[100004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		mp[s] = i;
		mp2[i] = s;
		book[i] = s;
	} // 포켓몬 입력

	for (int i = 1; i <= M; i++) {
		cin >> s;
		if (atoi(s.c_str()) == 0 ) {
			cout << mp[s] << "\n";
		}// 첫 글자가 문자라면
		else {
			cout << book[atoi(s.c_str())] << "\n";
		}// 숫자라면
	}
	return 0;
}