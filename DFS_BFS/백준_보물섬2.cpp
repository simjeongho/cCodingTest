#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

int n, m, mx, visited[54][54];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,1,0,-1 };
char map[54][54];

int Bfs(int y, int x) {
	//memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y, x });
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx]) continue;
			if (map[ny][nx] == 'W') continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
			mx = max(mx, visited[ny][nx]);
		}
	}
	return mx;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') Bfs(i, j);
		}
	}
	cout << mx - 1 << "\n";
}