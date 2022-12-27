#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c;
int N, L, R;
int A[50][50];
int B[50][50];
int visited[50][50];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
vector <pair<int, int>> v;
int dfs(int y, int x) {
	int ret = A[y][x];
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;
		
		int temp = A[ny][nx] - A[y][x];
		if (temp < 0) temp = -temp;
		if (temp >= L && temp<= R) {
			v.push_back({ ny, nx });
			ret += dfs(ny, nx);
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	
	int cnt = 0;
	while (1) {
		int flag = 0;
		memcpy(&B, &A, sizeof(A));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int ret;
				ret = dfs(i, j);
				int temp = v.size() + 1;
				if (temp - 1) {
					B[i][j] = ret / temp;
					for (int k = 0; k < temp - 1; k++) B[v[k].first][v[k].second] = ret / temp;				
					flag = 1;
				}
				v.clear();	
			}
		}
		memcpy(&A, &B, sizeof(B));
		memset(visited, 0, sizeof(visited));
		if (flag == 0) {
			cout << cnt << "\n";
			break;
		}
		else cnt++;
		
	}
	return 0;
}