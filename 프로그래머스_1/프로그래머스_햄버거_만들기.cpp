#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> ingredient) {
	int answer = 0;
	int cnt = 0;
	stack<int> st;
	st.push(ingredient[0]);
	for (int i = 1; i < ingredient.size(); i++) {
		if (ingredient[i] == 1) {
			cnt++; cout << "cnt:" << cnt << "\n";
		}
		else if (ingredient[i] == 2) {
			if (st.top() == 1) { cnt++; cout << "cnt:" << cnt << "\n";
			}
			else cnt = 0;
		}
		else {
			if (st.top() == 2) { cnt++; cout << "cnt:" << cnt << "\n";
			}
			else cnt = 0;
		}
		st.push(ingredient[i]);
		if (cnt == 4) {
			for (int i = 0; i < 4; i++) {
				st.pop();
			}
			if (st.top() == 1) { cnt = 1; cout << "cnt:" << cnt << "\n";
			}
			answer++;
		}
	}
	
	cout << "answer" << answer << "\n";
	return answer;
}

int main() {
	vector<int> ingredient = { 2,1,1,2,3,1,2,3,1 };
	solution(ingredient);

	return 0;
}