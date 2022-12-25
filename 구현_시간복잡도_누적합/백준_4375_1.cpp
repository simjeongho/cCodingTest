#include <iostream>
#include <string>
using namespace std;

int n;
string s = "1";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (scanf_s("%d", &n) != EOF) {
		int cnt = 1, ret = 1;
		while (1) {
			if (cnt % n == 0) {
				printf("%d\n", ret);
				break;
			}
			else {
				cnt = (cnt * 10) + 1;
				cnt %= n;
				ret++;
			}
		}
	}
	return 0;
}