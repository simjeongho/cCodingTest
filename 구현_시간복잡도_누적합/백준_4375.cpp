#include <iostream>
#include <string>
using namespace std;

int n;
string s = "1";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (scanf_s("%d", &n) != EOF) {
		while (1) {
			if (atoll(s.c_str()) % n == 0) {
				cout << s.length() << "\n";
				break;
			}
			else {
				s += "1";
			}
		}
	}
	
	
	return 0;
}