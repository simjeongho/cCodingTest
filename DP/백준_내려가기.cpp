/*
	DP문제 예전에 그 연습문제와 비슷한 거 같다. 
	풀어볼 것

	입력
	N  N개의 줄을 의미한다.
	숫자는 0,1,2,3,4,5,6,7,8,9,중 하나

	츨력
	얻을 수 있는 최대와 최소 점수를 각각 출력해야한다.
*/
#pragma warning (disable:4996)
#include <cstdio>
#include <algorithm>
//줄
using namespace std;
#define MAX 100000
int N;
int maps[MAX][3];
int maxMap[MAX][3];
int max1;
int min1 = 2000000000;
void input() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &maps[i][j]);
		}
	}
}
void makeMaxMap() {
	//아래에서 위를 봐야하나 
	//로직은 위의 가능한 경우의 수 중 가장 큰 쪽으로 이동하는 것
	copy(&maps[0][0], &maps[0][0] + N * 3, &maxMap[0][0]);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				maxMap[i][j] += (maxMap[i - 1][j] < maxMap[i - 1][j + 1] ? maxMap[i - 1][j + 1] : maxMap[i - 1][j]);
			}
			else if (j == 1) {
				maxMap[i][j] += max(max(maxMap[i - 1][j], maxMap[i - 1][j - 1]), maxMap[i - 1][j + 1]);
			}
			else {
				maxMap[i][j] += (maxMap[i - 1][j] < maxMap[i - 1][j -1] ? maxMap[i - 1][j - 1] : maxMap[i - 1][j]);
			}
		}
	}
	max1 = max(max(maxMap[N - 1][0], maxMap[N - 1][1]), maxMap[N - 1][2]);
}
void makeMinMap() {
	//아래에서 위를 봐야하나 
	//로직은 위의 가능한 경우의 수 중 가장 큰 쪽으로 이동하는 것
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				maps[i][j] += (maps[i - 1][j] < maps[i - 1][j + 1] ? maps[i - 1][j] : maps[i - 1][j+1]);
			}
			else if (j == 1) {
				maps[i][j] += min(min(maps[i - 1][j], maps[i - 1][j - 1]), maps[i - 1][j + 1]);
			}
			else {
				maps[i][j] += (maps[i - 1][j] < maps[i - 1][j - 1] ? maps[i - 1][j] : maps[i - 1][j-1]);
			}
		}
	}
	min1 = min(min(maps[N-1][0], maps[N-1][1]), maps[N-1][2]);
}

int main() {

	input();

	makeMaxMap();

	makeMinMap();

	printf("%d %d", max1, min1);
	return 0;
}



