#pragma warning (disable : 4996)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dy[4] = { -1,1,0,0 }; // udlr
int dx[4] = { 0,0, -1,1 };
int n, m;
char maps[1001][1001];
bool visited[1001][1001];
int ans;
void dfs(int y, int x) {
	if (visited[y][x]) return;
	visited[y][x] = 1;
	int ny = 0; int nx = 0;
	if (maps[y][x] == 'U') {
		ny = y + dy[0];
		nx = x + dx[0];
	}
	else if (maps[y][x] == 'D') {
		ny = y + dy[1];
		nx = x + dx[1];
	}
	else if (maps[y][x] == 'L') {
		ny = y + dy[2];
		nx = x + dx[2];
	}
	else {
		ny = y + dy[3];
		nx = x + dx[3];
	}
	if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
		dfs(ny, nx);
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (visited[ny][nx]) continue;
		if (i == 0) {
			//한 칸 위에 있을 때 다운이면 포함
			if (maps[ny][nx] == 'D') {
				dfs(ny, nx);
			}
		}
		else if (i == 1) {
			if (maps[ny][nx] == 'U') {
				dfs(ny, nx);
			}
		}
		else if (i == 2) {
			if (maps[ny][nx] == 'R') {
				dfs(ny, nx);
			}
		}
		else {
			if (maps[ny][nx] == 'L') {
				dfs(ny, nx);
			}
		}
	}
}
void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maps[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}