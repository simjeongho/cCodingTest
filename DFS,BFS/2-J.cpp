#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int h; //세로
int w; // 가로

char input[100][100];
int output[100][100];
int minute = 0;
int flag = 0;

int main()
{
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> input[i][j];
		}
	} // 입력 

	for (int i = 0; i < h; i++) {
		
		for (int j = 0; j < w; j++) {
			if (flag == 0 && input[i][j] != 'c') output[i][j] = -1;
			if (flag == 1 && input[i][j] != 'c') {
				minute += 1;
				output[i][j] = minute;
			}
			if (input[i][j] == 'c') {
				output[i][j] = 0;
				flag = 1;
				minute = 0;
			}
		}
		flag = 0;
		minute = 0;
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << output[i][j] << " ";
		}
		cout << "\n";
	}
}