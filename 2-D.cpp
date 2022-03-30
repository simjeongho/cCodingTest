#include <iostream>
#include <algorithm>

#include <vector>
using namespace std;
int m, n, k; //가로 세로 직사각형의 좌표
int a[101][101]; // map
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<int> ret;
int x1, y1, x2, y2;//정사각형 좌표
  
int dfs(int y, int x){
	a[y][x] = 1;
	int _ret = 1;
	for(int i=0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 || nx < 0 || ny > m || nx > n || a[ny][nx] == 1) continue;
		_ret += dfs(ny, nx);
	}
	return _ret;
}
int main() {
	cin >> m;
	cin >> n;
	cin >> k;
	fill(&a[0][0], &a[0][0] + 101 * 101, 0);  
	for(int i= 0; i< k; i++){
		cin >> x1 >> y1 >> x2, y2;
		for(int j = y1; j < y2; j++){
			for(int u = x1; u < x2; u ++){
				a[j][u] = 1;
			}
		}
	} // 정사각형 1로 채워 넣기  
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 0)
			{
				ret.push_back(dfs(i,j));
			}
		}
	}
	sort(ret.begin(), ret.end());
	cout << ret.size() << endl;
	for(int _ret : ret) cout << _ret << endl;
	return 0;
} 
