#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int row;
int col;
char map[51][51];
int visited[51][51];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0, 1,0, -1 };
queue<pair<int, int>> q;
vector<int> b;
vector<pair<int, int>> Land;
int y, x;
int maxdist= 0;
void combi(int start, vector<pair<int, int>> v) {
	if (v.size() == 2) {
		// 두 개를 뽑은 후 수행할 코드 BFS
		/*for (int i = 0; i < row; i++) {
			for (int r = 0; r < col; r++) {
				visited[i][r] = 0;
			}
		}*/
		memset(visited, 0, sizeof(visited));
		queue<pair<int, int>> q;
		q.push({ v[0].first, v[0].second });
		visited[v[0].first][v[0].second] = 0;
		while (q.size()) {
			tie(y, x) = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= row || nx >= col || map[ny][nx] == 'W') continue; // 경계조건
				if (visited[ny][nx]) continue;
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
		if (maxdist < visited[v[1].first][v[1].second]) maxdist = visited[v[1].first][v[1].second];
			return;
		}// 기저사례
	
		for (int i = start + 1; i < Land.size(); i++) {
			v.push_back(Land[i]);
			combi(i, v);
			v.pop_back();
		}
	}
int main() {
	vector<pair<int, int>> vec;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'L')
			{
				Land.push_back({ i,j }); // 육지 정보 저장 
			}
		}
	}
	combi(-1, vec);
	cout << maxdist;
}
