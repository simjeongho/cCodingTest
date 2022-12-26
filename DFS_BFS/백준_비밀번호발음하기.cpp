#include <iostream>
#include <string>
using namespace std;
//a = 97, e = 101, i = 105, o = 111,u = 117
//a = 97, z == 122
string text;


int solution(string check) {
	char prev = 'A';
	int flag1 = 0, flag2 = 1, flag3 = 1;
	int vowelcount = 0, consocount = 0;
	if (check == "a" || check =="e" || check == "i" || check == "o" || check == "u") {
		cout << "<" << text << "> is acceptable." << "\n";
		return 0;
	}
	for (int i = 0; i < check.size(); i++) {
		if (prev == check[i] && prev !='e' && prev != 'o') {
			flag3 = 0;
			cout << "<" << text << "> is not acceptable." << "\n";
			return 0; //세 번쨰 조건 위배 
		}
		if (check[i] == 'a' || check[i] == 'e' || check[i] == 'i' || check[i] == 'o' || check[i] == 'u') {
			//cout << "1check" << "\n";
			flag1 = 1; // 첫번쨰 조건
			vowelcount++;
			if (vowelcount >= 3) {
				flag2 = 0;
				cout << "<" << text << "> is not acceptable." << "\n";
				return 0;
			} // 두 번쨰 
			consocount = 0;
		}
		else {
			vowelcount = 0;
			consocount++;
			if (consocount >= 3) {
				flag2 = 0;
				cout << "<" << text << "> is not acceptable." << "\n";
				return 0;
			}// 두 번쨰 
		}
		prev = check[i];
		//cout << "prev: " << prev << "\n";
	}
	if (flag1 == 1 && flag2 == 1 && flag3 == 1) {
		cout << "<" << text << "> is acceptable." << "\n";
		return 0;
	}
	else {
		cout << "<" << text << "> is not acceptable." << "\n";
		return 0;
	}
}
int main() {
	
	while (true) {
		cin >> text;
		if (text == "end")return 0;
		solution(text);
	}
	return 0;
}