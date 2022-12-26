#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>
#include <tuple>

using namespace std;
int T;
int N, M;
int K;
int mx = 10000000;
char map[101][101];
int visited[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int warnIndexR, warnIndexC;
int res = 0;
int Bfs(int y, int x, int K, vector<pair<int, int>>warn) {
    memset(visited, 0, 40804); //초기화
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({ y, x });
    while (q.size() && K != 0) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) { //4방향 검사 
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 1 || nx < 1 || ny > N || nx > M || visited[ny][nx] || map[ny][nx] == '#') continue; // 경계를 넘는다면 건너뒨다. 
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny, nx });
        }
        for (int i = 0; i < K; i++) {
            if (warn[i].first == y && warn[i].second == x) { // 만약 현재 벡터 안에 ny nx의 인덱스가 존재한다면 count++
                warn.erase(warn.begin() + i);
                K--;
                if (K == 0) {
                    mx = min(mx, visited[y][x] - 1);
                    break;
                }
                break;
            }
        }
    }
    //if(K !=0) mx = -1;
    if (mx == 10000000) mx = -1;
    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    //cin >> T;
    scanf_s("%d", &T);

    for (int i = 1; i <= T; i++) {
        cin >> N >> M >> K;
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= M; c++) {
                cin >> map[r][c];
                //scanf("%s", &map[r][c]);
                //scanf("%c", &map[r][c]);
            }
        }
        vector <pair<int, int>> warn(K);
        for (int u = 0; u < K; u++) {
            //cin >> warn[u].first >> warn[u].second;
            scanf_s("%d %d", &warn[u].first, &warn[u].second);
        };
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (map[i][j] != '#') {
                    res = Bfs(i, j, K, warn);
                }
            }
        }
        warn.clear();
        mx = 10000000;
        printf("#%d %d\n", i, res);
    }
    return 0;
}