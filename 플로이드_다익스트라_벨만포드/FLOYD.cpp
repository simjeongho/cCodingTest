#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int w[6][6] = {
	{0,0,0,0,0,0},
	{0,0,1,1000,1,5},
	{0,9,0,3,2,1000},
	{0,1000,1000,0,4,1000},
	{0,1000,1000,2,0,3},
	{0,3,1000,1000,1000,0},
};

int D[6][6];
int p[6][6];

void floyd2(int n, int w[][6], int D[][6], int p[][6]) {
	int i, j, k;
	//�ʱ�ȭ 
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			p[i][j] = 0;
			D[i][j] = w[i][j];
		}
	}
	//for (int i = 1; i <= 5; i++) {
	//	for (int j = 1; j <= 5; j++) {
	//		cout << D[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";
	for (k = 1; k <= n; k++) {// ����
		for (int i = 1; i <= n; i++) {//����
			for (int j = 1; j <= n; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {//k�� ���İ��� ����� ���� �� �۴ٸ� 
					p[i][j] = k; // ��ο� k�� �������ش�. �ٷ� ���� 0
					D[i][j] = D[i][k] + D[k][j]; // Distance���� �Ʊ� ���� �� ���� ���� �־��ش�. 
				}
			}
		}
	}
}
int cnt = 1;
void path(int i, int j) {
	/*if (cnt <= 1) {
		cnt++;
		cout << "The Shortest Path("  <<i << ", " << j << ") v" << i << "->";
	}*/
	if (p[i][j] != 0) {	
		path(i, p[i][j]);
		cout << "v" << p[i][j] << "-> ";
		path(p[i][j], j);
	}
}

void printPath(int i, int j) {
	cout << "The Shortest Path(" << i << ", " << j << ") v" << i << "->";
	path(i, j);
	cout << "v" << j <<"\n";
}

int main() {
	int n = 5;
	floyd2(n, w, D, p);
	cout << "D�迭" << "\n";

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << D[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "p�迭" << "\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << p[i][j] << " ";
		}
		cout << "\n";
	}
	printPath(5, 3);
	printPath(1, 3);
	printPath(2, 5);
}