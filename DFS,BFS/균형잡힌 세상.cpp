#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;
string text;
int N=0;

int solution(string text) {
	stack<char> s;
	int M = text.size();
	for(int i=0; i <M; i++) 
	{
		if (text[i] == '(' || text[i] == '[') {
			s.push(text[i]);
			//cout << "push\n stacksize: " << s.size() << "\n";
		}
		else if (text[i] == ')' || text[i] == ']') {
			if (s.size() == 0) { cout << "no\n"; return 0; }
			else {
				if (s.top() == '(' && text[i] == ')') {
					s.pop();
					//cout << "small\n";
				}
				else if (s.top() == '[' && text[i] == ']') {
					s.pop();
					//cout << "big\n";
				}
				else {
					cout << "no\n";
					return 0;
				}
			}
			
		}
	}
	if (s.size() == 0) cout << "yes\n";
	else cout << "no\n";
	return 0;
}

int main() {

	while (true) {
		getline(cin, text);
		if (text == ".") break;
		solution(text);
		
	}
	
	return 0;
}