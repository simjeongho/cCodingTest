#include <iostream>
using namespace std;
#define Low  9
#define Col  9
int Solution(int map[][Col]) {
	map[0][0] = 0; // ���� �� 
	//map[i-1][j] == �ٷξƷ� map[i][j-1] == ����
	for (int i = 0; i < Low; i++) {
		for (int j = 0; j < Col; j++) {
			if (map[i][j] == 2) continue;//���� ������ �ǳ� �ڴ�.
			if (i == 0 && j == 0) { 
				map[0][0] = 0;
				continue; 
			}// ó�� �ǳʶڴ�.
			if (i >= 1 && j >= 1) {
				if (map[i][j] == -1) map[i][j] = 0;// -1�̶�� ġ� ���� ���� ���� �����̹Ƿ� 0���� ������ش�.
				map[i][j - 1] >= map[i - 1][j]  ? map[i][j] += map[i][j - 1] : map[i][j] += map[i - 1][j] ;
			}
			if (i == 0) {
				if (map[i][j] == -1) map[i][j] = 0;// -1�̶�� ġ� ���� ���� ���� �����̹Ƿ� 0���� ������ش�.
				map[i][j] += map[i][j - 1];
			}
			if (j == 0) {
				if (map[i][j] == -1) map[i][j] = 0;// -1�̶�� ġ� ���� ���� ���� �����̹Ƿ� 0���� ������ش�.
				map[i][j] += map[i - 1][j];
			}
		}
	}
	return map[Low - 1][Col - 1];
}
int main() {
	//ġ��� 1 �㵣�� 2 �������� -1
	int map[Col][Low] =
	{
		{-1, -1, -1, -1, -1, -1, -1, -1,-1},
		{-1, -1, -1, -1, -1, 1, -1, -1,-1},
		{-1, 1, -1, -1, 1, -1, -1, -1,-1},
		{-1, -1, -1, -1, -1, 2, 1, 2,-1},
		{-1, 1, -1, 1, -1, -1, -1, -1,-1},
		{-1, -1, -1, -1, 1, 2, -1, -1,-1},
		{1, -1, 2, -1, -1, -1, -1, 1,-1},
		{-1, -1, -1, -1, -1, 1, -1, 2,-1},
		{-1, -1, 1, -1, -1, -1, -1, -1,-1},
	};

	cout << map[2][1] << "\n";

	for (int i = Low-1; i >=0; i--) {
		for (int j = 0; j < Col; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
	Solution(map);
	for (int i = Low-1; i >= 0 ; i--) {
		for (int j = 0; j < Col; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "+++++++++++++++++++++++++++++++++++++++++\n";
	cout << "result is : " << map[Low - 1][Col - 1] << "\n";
}

