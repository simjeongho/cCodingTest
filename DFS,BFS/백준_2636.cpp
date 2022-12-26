#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int R, C;
int ny, nx;
int cheese[101][101];
int visited[101][101];
int cnt, cnt2;
vector <pair<int, int>> v;
void solution(int y, int x)  {
	visited[y][x] = 1;
	if (cheese[y][x] == 1) {
		v.push_back({ y,x });
		return;
	}
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx]) continue; // 경계조건
		solution(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >>  C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> cheese[i][j];
		}
	}

	while (1) {
		cnt2 = 0;
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		v.clear();
		solution(0, 0);
		for (auto a : v) {
			cnt2++;
			cheese[a.first][a.second] = 0;
		}
		bool flag = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (cheese[i][j] != 0) flag = 1;
			}
		}
		cnt++;
		if (!flag) break;
	}
	cout << cnt << "\n" << cnt2 << "\n";
	return 0;
}