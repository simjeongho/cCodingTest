#pragma warning (disable : 4996)
/*
	�÷��̵� ���� �˰��򿡼� ����Ŭ�� ã�� ��
	�밢���� ���� ���캸�� �ȴ�. 
	�ڱ� �ڽ����� ���ƿ��� ��� �밢���� ���� ���ŵȴ�. 
*/
#include <cstdio>
#include <algorithm>
#define MAX 402
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int V, E; // ���� ���� �� 
ll dist[MAX][MAX]; // 3 * 400 * 400 = 480000 = .0.48MB
ll mins = INF;
void input() {
	scanf("%d %d", &V, &E);

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i != j) {
				dist[i][j] = INF;
			}
		}
	} // ���Ѵ�� �ʱ�ȭ
	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = c; // �Ÿ� �迭 �ʱ�ȭ
	}
}

void sol() {
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (i != j) {
					if (i == k) {
						dist[i][j] = min(dist[i][j], dist[k][j]);
					}
					else if (k == j) {
						dist[i][j] = min(dist[i][j], dist[i][k]);
					}
					else dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
				else {
					if (dist[i][j] == 0) {
						dist[i][j] = INF;
					}
					if (i != k) {
						//printf("dist[%d][%d] : %lld  dist[%d][%d] : %lld dist[%d][%d] : %lld\n", i, j, dist[i][j], i, k, dist[i][k], k, j, dist[k][j]);
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
						//printf("dist[%d][%d] : %lld\n", i, j, dist[i][j]);
					}
					if (dist[i][j] >= INF) dist[i][j] = 0;
				}
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i][i] != 0) {
			mins = min(mins, dist[i][i]);
		}	
	}

	printf("%lld\n", mins < INF ? mins : -1);
}
int main() {
	input();
	sol();
	return 0;
}