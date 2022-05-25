#include <iostream>
#include <tuple>
using namespace std;

pair<int, int> S[10]; // 물건의 weight와 value
int value[100][100];
int knapSack(pair<int, int> S[], int num, int limit) {
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= limit; j++) {
			int wi = S[i].first;
			int val = S[i].second;

			//i번째 포함하면 오버하는 경우 j는 현재 bag limit 
			if (wi > j) {
				value[i][j] = value[i - 1][j]; // 오버하면 그냥 들어간다. 
			}
			else {
				value[i][j] = max(value[i - 1][j],value[i - 1][j - wi] + val); // 오버 안하면 안 넣는 경우와 넣었을 때의 경우를 비교해서 더 큰 값 
			}
		}
	}
	//cout << value[num][limit];
	return value[num][limit];
}

void print(int i) {
	
}

int main() {
	int limit;
	int num;
	for (int i = 1; i <= 2; i++) {
		cout << "배낭 무게는?" << "\n";
		cin >> limit;

		cout << "물건의 개수는?" << "\n";
		cin >> num;

		for (int i = 1; i <= num; i++) {
			//cout << "물건의 무게는 ? " << "\n";
			cin >> S[i].first;
			//cout << "물건의 가치는? " << " \n";
			cin >> S[i].second;
		}

		int result = knapSack(S, num, limit);

		cout << "입력" << i << "에 대하여 가방에 담은 보석의 최대 가치: " << result << "\n";
	}
}
