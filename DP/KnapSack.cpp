#include <iostream>
#include <tuple>
using namespace std;

pair<int, int> S[10]; // ������ weight�� value
int value[100][100];
int knapSack(pair<int, int> S[], int num, int limit) {
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= limit; j++) {
			int wi = S[i].first;
			int val = S[i].second;

			//i��° �����ϸ� �����ϴ� ��� j�� ���� bag limit 
			if (wi > j) {
				value[i][j] = value[i - 1][j]; // �����ϸ� �׳� ����. 
			}
			else {
				value[i][j] = max(value[i - 1][j],value[i - 1][j - wi] + val); // ���� ���ϸ� �� �ִ� ���� �־��� ���� ��츦 ���ؼ� �� ū �� 
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
		cout << "�賶 ���Դ�?" << "\n";
		cin >> limit;

		cout << "������ ������?" << "\n";
		cin >> num;

		for (int i = 1; i <= num; i++) {
			//cout << "������ ���Դ� ? " << "\n";
			cin >> S[i].first;
			//cout << "������ ��ġ��? " << " \n";
			cin >> S[i].second;
		}

		int result = knapSack(S, num, limit);

		cout << "�Է�" << i << "�� ���Ͽ� ���濡 ���� ������ �ִ� ��ġ: " << result << "\n";
	}
}
