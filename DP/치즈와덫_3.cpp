#include <iostream>
using namespace std;
#define Low  9
#define Col  9
int Solution(int map[][Col]) {
	map[0][0] = 0; // 시작 점 
	//map[i-1][j] == 바로아래 map[i][j-1] == 왼쪽
	for (int i = 0; i < Low; i++) {
		for (int j = 0; j < Col; j++) {
			if (map[i][j] == 2) continue;//덫이 있으면 건너 뛴다.
			if (i == 0 && j == 0) { 
				map[0][0] = 0;
				continue; 
			}// 처음 건너뛴다.
			if (i >= 1 && j >= 1) {
				if (map[i][j] == -1) map[i][j] = 0;// -1이라면 치즈도 없고 덫도 없는 상태이므로 0으로 만들어준다.
				map[i][j - 1] >= map[i - 1][j]  ? map[i][j] += map[i][j - 1] : map[i][j] += map[i - 1][j] ;
			}
			if (i == 0) {
				if (map[i][j] == -1) map[i][j] = 0;// -1이라면 치즈도 없고 덫도 없는 상태이므로 0으로 만들어준다.
				map[i][j] += map[i][j - 1];
			}
			if (j == 0) {
				if (map[i][j] == -1) map[i][j] = 0;// -1이라면 치즈도 없고 덫도 없는 상태이므로 0으로 만들어준다.
				map[i][j] += map[i - 1][j];
			}
		}
	}
	return map[Low - 1][Col - 1];
}
int main() {
	//치즈는 1 쥐덫은 2 나머지는 -1
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

