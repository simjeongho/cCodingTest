#include <iostream>
#include <algorithm>

using namespace std;
int n, m; // ��ũ�� ��
int j; // ��� ���� 
int loc;
int bucketStart, bucketFinish;

int main() {
	cin >> n >> m; // ��ũ�� ���� ĭ �� �Է�
	if (m >= n || n > 10 || m < 1) return 0;
	cin >> j; //��� ���� �Է�
	if (j < 1 || j > 20) return 0;;
	bucketStart = 1;
	bucketFinish = m;
	int move = 0;
	for (int i = 0; i < j; i++) {
		cin >> loc; // ��� �������� ��ġ
		if (loc <= bucketFinish && loc >= bucketStart) continue;
		if (loc > bucketFinish) {
			move += loc - bucketFinish;
			bucketFinish = loc;
			bucketStart = bucketFinish - m + 1;
		}
		if (loc < bucketStart) {
			move += bucketStart - loc;
			bucketStart = loc;
			bucketFinish = bucketStart + m - 1;
		}
	}
	cout << move << "\n";
	return 0;
}