#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
int n, m, y,x;
int max_n = 104;
    int a[max_n][max_n];
    int visited[max_n][max_n]; // 입력 배열과 방문 배열 
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
int main() {
    for(int i = 0; i < n; i++){
        for(int j= 0; j < m;j++)
        {
            cin >>a[i][j];
        }
    }//입력 만들기 

    queue<pair<int, int>> q; // q설정
    visited[0][0] = 1;// 방문 정보를 넣는다. 
    q.push({0,0});
    while(q.size()) // q의 사이즈만큼 반복
    {
        tie(y,x) = q.front(); q.pop();
        for(int i =0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny > n || nx < 0 || nx > m || a[ny][nx] == 0) continue; // 경계조건과 0일 경우
            if(visited[ny][nx]) continue;// 방문을 이미 한 경우
            visited[ny][nx]  = visited[y][x] + 1;
            q.push({ny, nx});

        }
    }
    cout << visited[n-1][m-1] << endl;
    return 0;
}