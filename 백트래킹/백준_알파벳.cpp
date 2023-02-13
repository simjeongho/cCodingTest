#pragma warning (disable : 4996)

#include<iostream>
#include <algorithm>
using namespace std;

int R, C;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };
char maps[22][22];
int visited[22][22]; // 방문배열
bool alphabet[26];
int cnt = 1;// 1의 개수 
int ans;// 정답
void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> maps[i][j]; // 입력을 받는다. 
		}
	}
}

void dfs(int y, int x) {
	visited[y][x] = 1; // 방문 배열 체크
	alphabet[maps[y][x] - 'A'] = 1; //알파벳 체크
	for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx])continue;
			if (alphabet[maps[ny][nx] - 'A']) continue; //이미 나온 알파벳이면 건너뛴다. 
			cnt++;
			dfs(ny, nx); // 추가 재귀함수
			cnt--;
			visited[ny][nx] = 0;
			alphabet[maps[ny][nx] - 'A'] = 0;
	}
	ans = max(ans, cnt);
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	dfs(0, 0);

	printf("%d\n", ans);
	return 0;
}