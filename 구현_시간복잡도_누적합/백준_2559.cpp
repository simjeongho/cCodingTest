#include <iostream>
#include <algorithm>

//������
using namespace std;

int N;
int K;
int date[100001];
int res = -10000004; // �ּڰ��� �Ű澴��.
int temp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> temp; date[i] = date[i - 1] + temp;
	}

	for (int i = K; i <= N; i++) {
		res = max(res, date[i] - date[i - K]);
	}
	cout << res << "\n";

	return 0;
}