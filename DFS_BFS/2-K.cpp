#include <iostream>
#include <algorithm>
//#include <vector>
using namespace std;
int T; // °³¼ö
int n;
int two = 0;
int five = 0;
//vector<long long> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		two = 0; five = 0;
		for (int j = 2; j <= n; j *= 2) {
			two += n / j;
		}
		for (int u = 5; u <= n; u *= 5) {
			five += n / u;
		}

		cout << min(two, five) << endl;
		
	}
	
	return 0;
}