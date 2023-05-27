#pragma warning (disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
int T;
int N, M;
struct bridge {
	int dest;
	int cost;
};
vector<bridge> AL[1001];
bool visited[1001];
bool isLeaf[1001];
int dfs(int num, int cost) {
	if (isLeaf[num]) return cost;
	int temp = 0;
	visited[num] = 1;

	for (auto bridge : AL[num]) {
		int nn = bridge.dest;
		int ncost = bridge.cost;
		if (visited[nn]) continue;
		temp += dfs(nn, ncost);
	}
	return min(temp, cost);
}
int ans;
int main() {

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);

		for (int j = 0; j < M; j++) {
			int s, e, c;
			scanf("%d %d %d", &s, &e, &c);
			AL[s].push_back({ e,c });
			AL[e].push_back({ s, c });
		}
		for (int i = 2; i <= N; i++) {
			if (AL[i].size() == 1) {
				isLeaf[i] = 1;
			}
		}
		int ans = 0;
		visited[1] = 1;
		for (int i = 0; i < AL[1].size(); i++) {
			ans += dfs(AL[1][i].dest, AL[1][i].cost);
		}
		printf("%d\n", ans);
		for (int i = 1; i <= N; i++) {
			AL[i].clear();
		} // Á¤¸®
		memset(isLeaf, 0, sizeof(isLeaf));
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}