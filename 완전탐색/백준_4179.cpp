#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int fire_check[1004][1004];
int person_check[1004][1004];
int visited[1004][1004];
int R, C;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };
int tx, ty;
char maps[1004][1004];
vector <pair<int, int>> fire;
queue<pair<int, int>> q;
int answer = 1000;
bool flag = 0;
string imp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 'F') {
				fire.push_back({ i,j });
			}
			if (maps[i][j] == 'J') {
				ty = i;
				tx = j;
			}
		}
	}
	for (int u = 0; u < fire.size(); u++) {
		int y = fire[u].first;
		int x = fire[u].second;
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				visited[j][k] = 0;
			}
		}
		fire_check[y][x] = 1;
		visited[y][x] = 1;
		q.push({ y, x });
		while (q.size()) {
			tie(y, x) = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny > R || nx > C || visited[ny][nx] || maps[ny][nx] == '#') continue;
				q.push({ ny, nx });
				visited[ny][nx] = visited[y][x] + 1;
				if (fire_check[ny][nx] == 0) {
					fire_check[ny][nx] = fire_check[y][x] + 1;
				}
				else {
					fire_check[ny][nx] = min(fire_check[ny][nx], visited[ny][nx]);
				}
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << fire_check[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	q.push({ ty, tx });
	if (tx == 0 || ty == 0 || ty == R - 1 || tx == C - 1) {
		cout << 1 << '\n';
		return 0;
	}
	person_check[ty][tx] = 1;
	while (q.size()) {
		tie(ty, tx) = q.front(); q.pop();
		
		for (int i = 0; i < 4; i++) {
			int ny = ty + dy[i];
			int nx = tx + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C || person_check[ny][nx] || maps[ny][nx] == '#') continue;
			if (ny == R - 1 || nx == C - 1 || ny == 0 || nx == 0) {
				if (fire.size()) {
					if (fire_check[ny][nx] > person_check[ty][tx] + 1) {
						flag = 1;
						answer = min(answer, person_check[ty][tx] + 1);
					}
				}
				else {
					flag = 1;
					answer = min(answer, person_check[ty][tx] + 1);
				}
				
			}
			person_check[ny][nx] = person_check[ty][tx] + 1;
			q.push({ ny, nx });
		}
	}
	if (flag) cout << answer << "\n";
	else cout << "IMPOSSIBLE" << "\n";
	/*cout << "\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << person_check[i][j] << " ";
		}
		cout << "\n";
	}*/
	return 0;
}