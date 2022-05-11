#include <iostream>
using namespace std;
#define Low  9
#define Col  9
int Solution(int map[][Col]) {
	map[0][0] = 0; // ½ÃÀÛ Á¡ 
	//map[i-1][j] == ¹Ù·Î¾Æ·¡ map[i][j-1] == ¿ÞÂÊ
	for (int i = 0; i < Low; i++) {
		for (int j = 0; j < Col; j++) {
			if (map[i][j] == -1) continue;//µ£ÀÌ ÀÖÀ¸¸é °Ç³Ê ¶Ú´Ù.
			if (i == 0 && j == 0) continue;// Ã³À½ °Ç³Ê¶Ú´Ù.
			if (i >= 1 && j >= 1) {
			 map[i][j - 1] >= map[i - 1][j] ? map[i][j] += map[i][j - 1] : map[i][j] += map[i - 1][j];
			}
			if(i == 0){
				map[i][j] += map[i][j - 1];
			}
			if(j==0) {
				map[i][j] += map[i - 1][j];
			}
		}
	}
	return map[Low - 1][Col - 1];
}
int main() {
	/*int map[Col][Low] =
	{
		{0, 0, 1, 0, 0, 0, 0, 0,0},
		{0, 0, 0, 0, 0, 1, 0, -1,0},
		{1, 0, -1, 0, 0, 0, 0, 1,0},
		{0, 0, 0, 0, 1, -1, 0, 0,0},
		{0, 1, 0, 1, 0, 0, 0, 0,0},
		{0, 0, 0, 0, 0, -1, 1, -1,0},
		{0, 1, 0, 0, 1, 0, 0, 0,0},
		{0, 0, 0, 0, 0, 1, 0, 0,0},
		{0, 0, 0, 0, 0, 0, 0, 0,0},
	};*/
	int map[Col][Low] =
	{
		{0, 0, 0, 0, 0, 0, 0, 0,0},
		{0, 0, 0, 0, 0, 1, 0, 0,0},
		{0, 1, 0, 0, 1, 0, 0, 0,0},
		{0, 0, 0, 0, 0, -1, 1, -1,0},
		{0, 1, 0, 1, 0, 0, 0, 0,0},
		{0, 0, 0, 0, 1, -1, 0, 0,0},
		{1, 0, -1, 0, 0, 0, 0, 1,0},
		{0, 0, 0, 0, 0, 1, 0, -1,0},
		{0, 0, 1, 0, 0, 0, 0, 0,0},
	};
	cout << map[2][1] << "\n";

	for (int i = 0; i < Low; i++) {
		for (int j = 0; j < Col; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
	Solution(map);
	for (int i = 0; i < Low; i++) {
		for (int j = 0; j < Col; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

