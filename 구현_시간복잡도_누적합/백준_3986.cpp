#include <iostream>
#include <stack>
using namespace std;

int N;
string word;
stack <char> st;
int res = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word;
		if (word.size() & 1) continue;
		else {
			for (int i = 0; i < word.size(); i++) {
				if (st.empty()) {
					st.push(word[i]);
					continue;
				}
				else {
					if (st.top() == word[i]) {	
						st.pop();
					}
					else {
						st.push(word[i]);
					}
				}
			}
			if (st.size() == 0) res++;
		}
		while (!st.empty()) {
			st.pop();
		}
	}
	cout << res << "\n";
	return 0;
}