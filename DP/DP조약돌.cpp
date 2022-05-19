#include <iostream>
#include <algorithm>
using namespace std;
#define col 8
#define row 3
int map[row][col] = {
	{6,7,12,-5,5,3,11,3},
	{-8,10,14,9,7,13,8,5},
	{11,12,7,4,8,-2,9,4},
};
int peb[row+1][col];

int maxPeb(int i, int p) {
	if (p == 0) {
		return max(peb[1][i-1], peb[2][i-1]);
	}
	else if (p == 1) {
		int maxre = max(peb[0][i-1], peb[2][i - 1]);
		return max(maxre, peb[3][i-1]);
	}
	else if (p == 2) {
		return max(peb[0][i - 1], peb[1][i - 1]);
	}
	else if (p == 3) {
		return peb[1][i-1];
	}
	else {
		cout << "error" << "\n";
		return 0;
	}
	return 0;
}
int pebble(int n) {
	for (int p = 0; p < 3; p++) {
		peb[p][0] = map[p][0];
	}
	peb[3][0] = map[0][0] + map[2][0];
	cout << "\n";

	for (int i = 1; i < n; i++) {
		for (int p = 0; p < 4; p++) {
			if (p == 3) {
				peb[p][i] = peb[1][i-1] + map[0][i] + map[2][i];
			}
			else {
				peb[p][i] = maxPeb(i, p) + map[p][i];
			}
		}
	}
	return 0;
}

int main() {
	for (int i = 0; i < row; i++) {
		for (int u = 0; u < col; u++) {
			cout << map[i][u] << " ";
		}
		cout << "\n";
	}

	pebble(col);
	cout << "\n";

	for (int i = 0; i < row+1; i++) {
		for (int u = 0; u < col; u++) {
			cout << peb[i][u] << " ";
		}
		cout << "\n";
	}
	return 0;
}