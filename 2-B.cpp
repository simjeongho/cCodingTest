#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int m,n,k;// ���� �� ���̿� ����
int ret;
int x, y; // ����
int ny, nx;//�ؽ�Ʈ ����  
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
		fill(&a[0][0], &a[0][0] + 51 * 51, 0); // 0���� �ʱ�ȭ
		fill(&visited[0][0], &visited[0][0]+ 51 * 51, 0); // 0���� �ʱ�ȭ 
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
