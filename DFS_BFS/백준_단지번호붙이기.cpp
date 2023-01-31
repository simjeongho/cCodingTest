#pragma warning (disable: 4996)

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 25+1
using namespace std;

char maps[MAX][MAX];
int visited[MAX][MAX];
int N;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
vector<int> v;
void input() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> maps[i][j];
		}
	}
}

int dfs(int y, int x) {
	int cnt = 1;
	if (maps[y][x] == '0' || visited[y][x]) {
		return 0;
	}
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx] || maps[ny][nx] == '0') continue;
		cnt += dfs(ny, nx);
	}
	return cnt;
}
int main() {

	input();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x = dfs(i, j);
			if (x != 0) {
				v.push_back(x);
			}
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << "\n";
	for (int a : v) {
		cout << a << "\n";
	}
	return 0;
}