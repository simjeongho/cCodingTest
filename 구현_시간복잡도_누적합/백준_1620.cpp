#include <iostream>
#include <algorithm>
#include <string>
#include <map>
//Map�� ����Ѵ�.
//Map�� Ž�� �ð� ���⵵�� logN
using namespace std;

int N; // ���ϸ� ����
int M; //������ϴ� ������ ����
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
	} // ���ϸ� �Է�

	for (int i = 1; i <= M; i++) {
		cin >> s;
		if (atoi(s.c_str()) == 0 ) {
			cout << mp[s] << "\n";
		}// ù ���ڰ� ���ڶ��
		else {
			cout << book[atoi(s.c_str())] << "\n";
		}// ���ڶ��
	}
	return 0;
}