#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <utility>
#include <climits>
#include <cmath>
#include <deque>
#include <cstdlib>
using namespace std;

int dx[4] = { 0, -1, 0, 1 }; //0 == right, 1 == up, 2 == left, 3 == down
int dy[4] = { 1, 0, -1, 0 };

int N, M;
int cctv[8][8]; // 0 빈칸, 1 ~ 5 cctv, 6 벽
vector<pair<int, int> > cctv_pos;
int res = 64;


//x,y에 위치한 cctv가 dir방향을 감시
void check(int x, int y, int dir) {
    dir %= 4; //가능한 감시방향 right, up, left, down (0 ~ 3)
    while (true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if (nx < 0 || ny < 0 || nx >= N || ny >= M)return;
        if (cctv[nx][ny] == 6) return;
        if (cctv[nx][ny] != 0) continue;
        cctv[nx][ny] = '#';
    }
}


//idx번째 cctv를 회전
void solve(int idx) {
    int cctv_cnt = cctv_pos.size();
    if (idx == cctv_cnt) { //모든 cctv를 다 확인했을 때
        int temp_res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (cctv[i][j] == 0) temp_res++;
            }
        }
        res = min(res, temp_res);
        return;
    }
    int x = cctv_pos[idx].first;
    int y = cctv_pos[idx].second;
    int backup[8][8];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            backup[i][j] = cctv[i][j];
        }
    }
    for (int dir = 0; dir < 4; dir++) { //4번까지 회전시켜본다
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                backup[i][j] = cctv[i][j];
            }
        }
        /*dir 1증가하면 90도 회전*/
        if (cctv[x][y] == 1) {
            check(x, y, dir); //dir == 0 일때 right
        }
        else if (cctv[x][y] == 2) {
            check(x, y, dir); //dir == 0 일때 right
            check(x, y, dir + 2); //dir == 0 일때 left

        }
        else if (cctv[x][y] == 3) {
            check(x, y, dir); //dir == 0 일때 right
            check(x, y, dir + 1); //dir == 0 일때 up
        }
        else if (cctv[x][y] == 4) {
            check(x, y, dir); //dir == 0 일때 right
            check(x, y, dir + 1); //dir == 0 일때 up
            check(x, y, dir + 2); //dir == 0 일때 left

        }
        else if (cctv[x][y] == 5) {
            check(x, y, dir); //dir == 0 일때 right
            check(x, y, dir + 1); //dir == 0 일때 up
            check(x, y, dir + 2); //dir == 0 일때 left
            check(x, y, dir + 3); //dir == 0 일때 down
        }
        solve(idx + 1); //다음 cctv 회전시키기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cctv[i][j] = backup[i][j];
            }
        }
    }
}



int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> cctv[i][j];
            if (cctv[i][j] >= 1 && cctv[i][j] <= 5) {
                cctv_pos.push_back({ i, j });
            }
        }
    }
    solve(0);
    cout << res;

    return 0;
}
