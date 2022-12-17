#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <string.h>

using namespace std;
#define MAX 4
int direction[MAX];
int Arr[4] = { 1,2,3,4 };
int N, M, K;
int map[101][101];
int maxPeople;
int myCopy[101][101];
//Áßº¹ ¼ø¿­ 
void solution(int cnt, int K, int M, int N) {
    //int myCopy[101][101];
    memset(myCopy, 0, 40804); //ÃÊ±âÈ­
    for (int i = 1; i <= N; i++) {
        for (int u = 1; u <= M; u++) {
            myCopy[i][u] = map[i][u];
        }
    }
    if (cnt == K) { // ¸¸¾à ¹Ù¶÷ÀÇ °³¼ö¸¸Å­ »ÌÈ÷¸é 
        for (int i = 0; i < K; i++) {
            switch (direction[i]) {
            case 1: // µ¿Ç³
                for (int r = 1; r <= N; r++) {
                    for (int c = M; c > 1; c--) {
                        if (myCopy[r][c]) {
                            myCopy[r][c - 1] += myCopy[r][c];
                            myCopy[r][c] = 0;
                            break;
                        }
                    }
                }
                break;
            case 2: //¼­Ç³      
                for (int r = 1; r <= N; r++) {
                    for (int c = 1; c < M; c++) {
                        if (myCopy[r][c]) {
                            myCopy[r][c + 1] += myCopy[r][c];
                            myCopy[r][c] = 0;
                            break;
                        }
                    }
                }
                break;
            case 3: //³²Ç³

                for (int c = 1; c <= M; c++) {
                    for (int r = N; r > 1; r--) {
                        if (myCopy[r][c]) {
                            myCopy[r - 1][c] += myCopy[r][c];
                            myCopy[r][c] = 0;
                            break;
                        }
                    }
                }
                break;
            case 4: //ºÏÇ³   
                for (int c = 1; c <= M; c++) {
                    for (int r = 1; r < N; r++) {
                        if (myCopy[r][c]) {
                            myCopy[r + 1][c] += myCopy[r][c];
                            myCopy[r][c] = 0;
                            break;
                        }
                    }
                }
                break;
            }

            for (int r = 1; r <= N; r++) {
                for (int c = 1; c <= M; c++) {
                    if (maxPeople < myCopy[r][c]) maxPeople = myCopy[r][c];
                }
            }

        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        direction[cnt] = Arr[i];
        solution(cnt + 1, K, M, N);
    }

}
int main() {
    ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int res = 0;
        scanf("%d %d %d", &N, &M, &K);
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= M; c++) {
                scanf("%d", &map[r][c]);
            }
        }

        solution(0, K, M, N);



        printf("#%d %d\n", i, maxPeople);
        maxPeople = 0;
    }
}
