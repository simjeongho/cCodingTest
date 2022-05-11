#include <iostream>

using namespace std;

#define LOW 9
#define COL 9
void cheese(int twoDimension[][LOW + 2]) {
    for (int i = COL; i >= 1; i--) {
        for (int j = 1; j <= LOW; j++) {
            if (twoDimension[i][j] != -1) {
                twoDimension[i][j] += (twoDimension[i][j - 1] < twoDimension[i + 1][j] ? twoDimension[i + 1][j] : twoDimension[i][j - 1]);
            }
        }
    }
    cout << twoDimension[1][LOW] << endl;
    for (int i = 0; i < COL + 2; i++) {
        for (int j = 0; j < LOW + 2; j++) {
            cout << twoDimension[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int twoDimension[COL + 2][LOW + 2] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0 ,0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0 ,0, 0, 0, 0, 0, 1, 0, -1, 0, 0},
        {0, 1, 0, -1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, -1, 1, -1, 0, 0},
        {0 ,0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    cheese(twoDimension);

    return 0;
}
