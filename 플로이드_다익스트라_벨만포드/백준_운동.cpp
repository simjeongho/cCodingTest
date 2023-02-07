#pragma warning (disable : 4996)
/*
	플로이드 워셜 알고리즘에서 사이클을 찾는 법
	대각선의 값을 살펴보면 된다. 
	자기 자신으로 돌아오는 경우 대각선의 값이 갱신된다. 
*/
#include <cstdio>
#include <algorithm>
#define MAX 402
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int V, E; // 노드와 간선 수 
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
	} // 무한대로 초기화
	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = c; // 거리 배열 초기화
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