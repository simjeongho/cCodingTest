#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int cheese[101][101];
int visited[101][101];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1, 0,1,0 };
int res;
int cheeseCnt;
vector <pair<int, int>> v;
vector <pair<int, int>> v2;
void sol(int y, int x) {
	visited[y][x] = 1;
	if (cheese[y][x] == 1) {
		visited[y][x]++;
		v.push_back({ y, x });
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
		sol(ny, nx);
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> cheese[i][j];
			if (cheese[i][j] == 1) cheeseCnt++;
		}
	}
	while (1) {
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0); // visited map �ʱ�ȭ
		v.clear();
		sol(0, 0);
		for (auto a : v) {
			int cnt = 0;
			for (int i = 0; i < 4; i++) {
				int ny = a.first + dy[i];
				int nx = a.second + dx[i];
				if (visited[ny][nx] == 1) {
					cnt++;
					if (cnt >= 2) {
						cheese[a.first][a.second] = 0;
						cheeseCnt--;
						break;
					}
					if (cheeseCnt == 0) break;
				}
			}
		}
		res++;
		if (cheeseCnt == 0) break;
	}	
	cout << res << "\n";
	return 0;
}