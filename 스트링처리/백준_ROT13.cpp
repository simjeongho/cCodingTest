#include <iostream>
#include <string>
using namespace std;
//대문자 A ~ Z == 65 ~ 90
//소문자 a ~ z == 97 ~ 122
int main() {
	string s;
	string copy;
	getline(cin, s);
	if (s.size() > 100) return 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= 90 && s[i] >= 65) {
			//대문자라면 
			if (s[i] <= 90 && s[i] >= 78) s[i] -= 13;
			else s[i] += 13;
		}
		else if (s[i] >= 97 && s[i] <= 122) {
			//소문자라면
			if (s[i] <= 122 && s[i] >= 110) s[i] -= 13;
			else s[i] += 13;
		}
		else {
			s[i] = s[i];
		}
	}
	cout << s;
}