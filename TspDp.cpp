#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <time.h>
#include <iostream>
#define MAX 987654321.0
using namespace std;

int n;

int memo[16][65536], dist[16][16];
vector<int> path;
int TSP(int cur, int visited) {
	//점이 10개라면, 10000000000 -1 0111111111
	if (visited == (1 << n) - 1) return dist[cur][0];

	int& ret = memo[cur][visited];
	ret = MAX;
	for (int next = 0; next <= n; next++) {
		if (visited & (1 << next)) continue;
		if (dist[cur][next] == 0) continue;
		ret = min(ret, TSP(next, visited | (1 << next)) + dist[cur][next]);
	}
	return ret;
}

void printPath(long double distance) {
	int piv = 0, masking = 1;
	//memo 배열을 탐색해가며 다음 경로를 찾는다. 
	for (int j = 0; j <= n; j++) {
		for (int k = 0; k <= n; k++) {
			if (masking & (1 << k))continue;
			if (distance - dist[piv][k] == memo[k][masking + (1 << k)]) {
				//다음 경로 저장
				path.push_back(k);
				distance = memo[k][masking + (1 << k)];
			}
		}
	}
	//경로 출력
	for (int i = 0; i < path.size(); i++) {
		printf("(%d->", path[i]);
	}
	printf("(0)");
}

int main() {
	clock_t start, finish;
	double duration;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &dist[i][j]);
		}
	}
	start = clock();
	printf("%d", TSP(0, 1));
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	cout << "duration : " << duration;
}