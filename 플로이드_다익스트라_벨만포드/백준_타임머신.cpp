#pragma warning (disable : 4996)

/*
	벨만포드는 모든 간선을 탐색하면서 간선의 출발 정점이 한 번이라도 계산된 정점일 경우 
	현재 거리에 간선의 weight를 더했을 때 더 작다면 거리를 update한다.

	따라서 모든 간선 정보를 저장할 공간이 필요하다.
	간선 정보는 
	출발정점 , weight , 도착 정점 세 가지 정보를 가지고 있어야한다.
	또한 update한 dist를 저장할 배열또한 필요하다. 
*/

#include <cstdio>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f
struct Edge {
	int start;
	int dest;
	int cost;
};
int N, M;
vector<Edge> Edges;
int dist[502];
void input() {
	scanf("%d %d", &N, &M);
	int A, B, C;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &A, &B, &C);
		Edges.push_back({ A, B, C });
	}
}

void BellmanFord() {
	//dist 배열 무한대로 초기화
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	//모든 간선 탐색
	//출발은 1번 도시 
	bool isNegCycle = false;
	dist[1] = 0;
	//N-1번 반복한다.
	for (int i = 1; i < N; i++) {
		for (int i = 0; i < M; i++) {
			//만약 초기화가 된 적 있는 노드라면
			//또한 도착 간선을 더한 값이 원래의 값 보다 더 작다면
			if (dist[Edges[i].start] != INF && dist[Edges[i].dest] > dist[Edges[i].start] + Edges[i].cost) {
				dist[Edges[i].dest] = dist[Edges[i].start] + Edges[i].cost;
			}
			//방문한 적 없다면 넘어간다.
			else continue;
			/*for (int j = 1; j <= N; j++) {
				printf("%d ", dist[j]);
			}
			printf("\n");*/
		}
	}
	//N번째 돌린다.
	for (int i = 0; i < M; i++) {
		if (dist[Edges[i].start] != INF && dist[Edges[i].dest] > dist[Edges[i].start] + Edges[i].cost) {
			dist[Edges[i].dest] = dist[Edges[i].start] + Edges[i].cost;
			isNegCycle = true;
		}
		//방문한 적 없다면 넘어간다.
		else continue;
	}
	if (isNegCycle) {
		puts("-1");
	}
	else {
		for (int i = 2; i <= N; i++) {
			printf("%d\n", dist[i] == INF ? -1 : dist[i]);
		}
	}
}
int main() {
	input();
	/*for (auto a : Edges) {
		printf("%d %d %d\n", a.start, a.dest, a.cost);
	}*/

	BellmanFord();
}