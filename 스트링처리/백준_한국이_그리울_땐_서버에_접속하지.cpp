#include <iostream>
#include <string>

using namespace std;
//a~z ==97~ 122
string pattern;
int n;
string text;
int solution(string text) {
	string pre;
	string suff;
	if (text.size() > 100) return 0;
	pre = pattern.substr(0, pattern.find("*")); // Á¢µÎ»ç 
	suff = pattern.substr(pattern.find("*")+1);

	cout << "pre: " << pre << "\n";
	cout << "suff: " << suff << "\n";

	text.substr(0, pre.size()) == pre && text.substr(text.size() - suff.size()) == suff ? cout << "DA\n" : cout << "NE\n";
	cout << "text.substr(0, pre.size()): " << text.substr(0, pre.size()) << "\n";
	cout << "text.substr(text.size() - suff.size()): " << text.substr(text.size() - suff.size()) <<"\n";
	return 0;
}
int main() {
	cin >> n;
	cin >> pattern;
	for (int i = 0; i < n; i++) {
		cin >> text;
		solution(text);
	}
	return 0;
}