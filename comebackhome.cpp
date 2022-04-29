#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int R, C;
int K;
char map[10][10];
int visited[10][10];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string s;
int dfs(int y, int x) {
	if (y == 0 && x == C - 1)
	{
		if (visited[y][x] == K) return 1;
		return 0;
	}
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx] || map[ny][nx] == 'T')continue; 
		visited[ny][nx] = visited[y][x] + 1;
		ret += dfs(ny, nx);
		visited[ny][nx] = 0;
	}
	return ret;
}
int main() {

	cin >> R >> C >> K;

	for (int i = 0; i < R; i++) {
		cin >> s;
		for (int j = 0; j < C; j++) {
			map[i][j] = s[j];
		}
	}
	visited[R - 1][0] = 1;
	cout << dfs(R - 1, 0) << "\n";


}