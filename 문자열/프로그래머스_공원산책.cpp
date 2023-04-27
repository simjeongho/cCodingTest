#include <string>
#include <vector>
#include <cstdio>

using namespace std;
int calculE(int T, int origin, int move) {
    int ret = 0;
    if (origin + move >= T) return origin;
    else return origin + move;
}
int calculS(int T, int origin, int move) {
    int ret = 0;
    if (origin + move >= T) return origin;
    else return origin + move;
}
int calculW(int T, int origin, int move) {
    int ret = 0;
    if (origin - move < 0) return origin;
    else return origin - move;
}
int calculN(int T, int origin, int move) {
    int ret = 0;
    if (origin - move < 0) return origin;
    else return origin - move;
}
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int startX = 0; int startY = 0; bool findFlag = 0;
    int targetX = 0; int targetY = 0;
    int H = park.size(); int W = park[0].size();
    printf("H : %d , W : %d\n", H, W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (park[i][j] == 'S') {
                startY = i;
                startX = j;
                targetY = startY;
                targetX = startX;
                findFlag = 1;
                break;
            }
        }
        if (findFlag) break;
    } // ½ÃÀÛ ÁÂÇ¥
    for (auto route : routes) {
        int move = stoi(string(route.begin() + 1, route.end()));
        printf("move : %d\n", move);
        if (route[0] == 'E') {
            bool flag = 0;
            for (int i = 1; i <= move; i++) {
                if (park[targetY][calculE(W, targetX, i)] == 'X') {
                    flag = 1;
                    break;
                }
            }
            if (!flag) targetX = calculE(W, targetX, move);
            printf("targetEX : %d\n", targetX);
        }
        else if (route[0] == 'W') {
            bool flag = 0;
            for (int i = 1; i <= move; i++) {
                if (park[targetY][calculW(W, targetX, i)] == 'X') {
                    flag = 1;
                    break;
                }
            }
            if (!flag) targetX = calculW(W, targetX, move);
            printf("targetWX : %d\n", targetX);
        }
        else if (route[0] == 'S') {
            bool flag = 0;
            for (int i = 1; i <= move; i++) {
                if (park[calculS(H, targetY, i)][targetX] == 'X') {
                    flag = 1;
                    break;
                }
            }
            if (!flag) targetY = calculS(H, targetY, move);
            printf("targetSY : %d\n", targetY);
        }
        else {
            bool flag = 0;
            for (int i = 1; i <= move; i++) {
                if (park[calculN(H, targetY, i)][targetX] == 'X') {
                    flag = 1;
                    break;
                }
            }
            if (!flag) targetY = calculN(H, targetY, move);
            printf("targetNY : %d\n", targetY);
        }
    }
    answer.push_back(targetY);
    answer.push_back(targetX);
    return answer;
}