#pragma warning (disable : 4996)

/*
	��������� ��� ������ Ž���ϸ鼭 ������ ��� ������ �� ���̶� ���� ������ ��� 
	���� �Ÿ��� ������ weight�� ������ �� �� �۴ٸ� �Ÿ��� update�Ѵ�.

	���� ��� ���� ������ ������ ������ �ʿ��ϴ�.
	���� ������ 
	������� , weight , ���� ���� �� ���� ������ ������ �־���Ѵ�.
	���� update�� dist�� ������ �迭���� �ʿ��ϴ�. 
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
	//dist �迭 ���Ѵ�� �ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	//��� ���� Ž��
	//����� 1�� ���� 
	bool isNegCycle = false;
	dist[1] = 0;
	//N-1�� �ݺ��Ѵ�.
	for (int i = 1; i < N; i++) {
		for (int i = 0; i < M; i++) {
			//���� �ʱ�ȭ�� �� �� �ִ� �����
			//���� ���� ������ ���� ���� ������ �� ���� �� �۴ٸ�
			if (dist[Edges[i].start] != INF && dist[Edges[i].dest] > dist[Edges[i].start] + Edges[i].cost) {
				dist[Edges[i].dest] = dist[Edges[i].start] + Edges[i].cost;
			}
			//�湮�� �� ���ٸ� �Ѿ��.
			else continue;
			/*for (int j = 1; j <= N; j++) {
				printf("%d ", dist[j]);
			}
			printf("\n");*/
		}
	}
	//N��° ������.
	for (int i = 0; i < M; i++) {
		if (dist[Edges[i].start] != INF && dist[Edges[i].dest] > dist[Edges[i].start] + Edges[i].cost) {
			dist[Edges[i].dest] = dist[Edges[i].start] + Edges[i].cost;
			isNegCycle = true;
		}
		//�湮�� �� ���ٸ� �Ѿ��.
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