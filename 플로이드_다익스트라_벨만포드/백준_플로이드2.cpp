#pragma warning (disable : 4996)
#include <cstdio>
#define INF  1987654321
int N, M; // N : 정점 ~100, M : 간선개수 ~ 10000
//인접 행렬 ---> 최단경로의 비용들이 저장되는 곳
long long AM[101][101];
inline int MIN(int a, int b) { return a < b ? a : b; }
int main() {
	scanf("%d %d", &N, & M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) AM[i][j] = INF;
		}
	}

	//간선 정보 받기
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		AM[a][b] = MIN(AM[a][b], c);
	}
	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", AM[i][j]);
		}
		puts("");
	}*/
	//플로이드 워셜 돌려야함 맨 밖이 경유지 k->i->j
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (AM[i][k] == INF && AM[k][j] == INF) continue;
				AM[i][j] = MIN(AM[i][j], AM[i][k] + AM[k][j]);
				//printf("AM[%d][%d]: %lld\n", i, j, AM[i][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", AM[i][j] == INF ? 0 : AM[i][j]);
		}
		puts("");
	}
}