#pragma warning (disable : 4996)

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
int t;
int N, M;
ll tree[32][32];
void makeTree() {
    tree[0][0] = 1;
    tree[1][0] = 1;
    tree[1][1] = 1;

    for (int i = 2; i < 30; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                tree[i][j] = 1;
            }
            else {
                tree[i][j] = tree[i - 1][j - 1] + tree[i - 1][j];
            }
        }
    }
}
int main(void) {
    scanf("%d", &t);
    makeTree();

    /*for (int i = 0; i < 29; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", tree[i][j]);
        }
        printf("\n");
    }*/
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &N, &M);
        printf("%d\n", tree[M][N]);
    }
}