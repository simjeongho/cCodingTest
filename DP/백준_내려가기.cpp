/*
	DP���� ������ �� ���������� ����� �� ����. 
	Ǯ� ��

	�Է�
	N  N���� ���� �ǹ��Ѵ�.
	���ڴ� 0,1,2,3,4,5,6,7,8,9,�� �ϳ�

	����
	���� �� �ִ� �ִ�� �ּ� ������ ���� ����ؾ��Ѵ�.
*/
#pragma warning (disable:4996)
#include <cstdio>
#include <algorithm>
//��
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
	//�Ʒ����� ���� �����ϳ� 
	//������ ���� ������ ����� �� �� ���� ū ������ �̵��ϴ� ��
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
	//�Ʒ����� ���� �����ϳ� 
	//������ ���� ������ ����� �� �� ���� ū ������ �̵��ϴ� ��
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



