#include <iostream>
#include <string>
using namespace std;
//�빮�� A ~ Z == 65 ~ 90
//�ҹ��� a ~ z == 97 ~ 122
int main() {
	string s;
	string copy;
	getline(cin, s);
	if (s.size() > 100) return 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= 90 && s[i] >= 65) {
			//�빮�ڶ�� 
			if (s[i] <= 90 && s[i] >= 78) s[i] -= 13;
			else s[i] += 13;
		}
		else if (s[i] >= 97 && s[i] <= 122) {
			//�ҹ��ڶ��
			if (s[i] <= 122 && s[i] >= 110) s[i] -= 13;
			else s[i] += 13;
		}
		else {
			s[i] = s[i];
		}
	}
	cout << s;
}