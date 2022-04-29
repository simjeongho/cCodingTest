#include<iostream>
#include<algorithm>
#include <tuple>
using namespace std;
int n;// 배열의 크기 가로 세로
int b[101][101];// 실제 map
int e[101][101]; 
int visited[101][101]; // 방문 배열
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0,1,0,-1}; // 인덱스 배열
int ret = 1; // 연결된 컴포넌트 개수

int temp; 
void dfs(int y, int x) {
	visited[y][x]=1; // 방문 처리  
	for(int i = 0; i< 4; i ++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >=  n) continue; // 경계조건 
		if(visited[ny][nx] == 0 && e[ny][nx] == 0) // 방문 안했고 생성 배열 구역이 안전구역이라면 dfs
		{
			dfs(ny, nx);
		}
	}
	return; 
} 
int main()
{
	ios_base::sync_with_stdio(false);
	
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n; // 가로 세로 길이 입력
	for( int i=0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	} // 높이 입력
	
	for( int d=1; d < 101; d++){
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		temp = 0;
		for(int i = 0; i < n; i ++){
			for(int j = 0; j< n; j++){
				if(e[i][j] == 1)continue;
				if(b[i][j] <= d) e[i][j] = 1;//1로 변환하는 배열 0이 안전 영역  
			}
		}
		for(int i = 0 ; i < n; i++){
			for(int j=0; j < n; j++){
				if(e[i][j] == 0 && !visited[i][j])
				{
					dfs(i, j);
					temp ++ ;
				}
			}
		}
		ret = max(ret, temp);
	}
	cout << ret << endl;
	return 0;
}
