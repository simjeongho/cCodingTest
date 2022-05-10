#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
int n;
int m;
int visited[104][104];
int map[104][104];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };
int ny, nx;
int y, x;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m; // 가로 세로 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	} // map입력

	queue <pair<int, int>> q;
	visited[0][0] = 1;
	q.push({ 0,0 });
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny<0 || nx <0 || ny >= n || ny >= m || map[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j]<<" ";
		}
		cout << "\n";
	}*/
	printf("%d\n", visited[n - 1][m - 1]);

	return 0;
}