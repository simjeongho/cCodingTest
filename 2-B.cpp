#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int m,n,k;// 배추 밭 넓이와 배추
int ret;
int x, y; // 배추
int ny, nx;//넥스트 배추  
int t;
int a[51][51];
bool visited[51][51];
void dfs(int y, int x){
	visited[y][x] = 1;
	for(int i=0;i<4;i++){
		ny = y + dy[i];
		nx = x + dx[i];
		if(ny<0||ny > 51 || nx < 0 || nx> 51)continue;
		if(a[ny][nx] == 1 && visited[ny][nx] == 0){
			dfs(ny, nx);
		}
	}
	return;
} 
int main() {
	cin.tie(NULL);
	cin.tie(NULL);
	cin >> t;
	while(t--){
		fill(&a[0][0], &a[0][0] + 51 * 51, 0); // 0으로 초기화
		fill(&visited[0][0], &visited[0][0]+ 51 * 51, 0); // 0으로 초기화 
		ret= 0;
		cin >> m >> n >> k;
		for(int i = 0; i < k; i++)
		{
			cin >> x >> y;
			a[y][x] = 1;
		}
		for(int i=0;i < n;i++){
			for(int j = 0; j < m; j++){
				if(a[i][j] == 1 && visited[i][j] == 0)
				{
					dfs(i, j);
					ret++;
				}
			}
		}
	cout << ret << endl;	
	}
	
	
	return 0;
}
