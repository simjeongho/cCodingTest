#include <iostream>

using namespace std;

#define col 9
#define row 8
void numberGame(int twoDimension[][col]) {
    for (int i = 1; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == 0) {
                twoDimension[i][j] += (twoDimension[i - 1][j] < twoDimension[i - 1][j + 1] ? twoDimension[i - 1][j + 1] : twoDimension[i - 1][j]);//행의 왼쪽 끝일 때 [i-1][j] == 바로 위 < [i-1][j+1] == 오른쪽 대각선 위라면 더 큰 걸 더해준다. 두 가지만 고려한다. 
                cout << "if : " << twoDimension[i][j] << "\n";
            }
            else if (j == col -1) {
                twoDimension[i][j] += (twoDimension[i - 1][j - 1] < twoDimension[i - 1][j] ? twoDimension[i - 1][j] : twoDimension[i - 1][j - 1]); //행이 오른쪽 끝일 때[i-1][j-1] = 왼쪽 대각선 위  < [i-1][j]바로 위라면 더 큰 걸 더해준다. 두 가지만 고려한다. 
                cout << "else if  : " << twoDimension[i][j] << "\n";
            }
            else {
                //행의 중간이라면 왼쪽 대각선 위와 바로 위를 비교 바로 위와 오른쪽 대각선 위를 비교 왼쪽 대각선 위가 더 크다면 왼쪽 대각선과 오른쪽 대각선을 비교  제일 큰 값 더해준다. 
                twoDimension[i][j] += (twoDimension[i - 1][j - 1] < twoDimension[i - 1][j] ? twoDimension[i - 1][j] < twoDimension[i - 1][j + 1] ? twoDimension[i - 1][j + 1] : twoDimension[i - 1][j] : twoDimension[i - 1][j - 1] < twoDimension[i - 1][j + 1] ? twoDimension[i - 1][j + 1] : twoDimension[i - 1][j - 1]);
                cout << "else   : " << twoDimension[i][j] << "\n";
            }
        }
        cout << "-----------------------------------------\n";
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 9; j++) {
                cout << twoDimension[i][j] << " ";
            }
            cout << "\n";
        }
    }
    int maxNum = 0;
    for (int i = 0; i < col; i++) {
        if (maxNum < twoDimension[row - 1][i]) maxNum = twoDimension[row - 1][i];
    }

    cout << maxNum << endl;
}

int main() {
    int twoDimension[row][col] =
    {
        {3,4,9,-2,2,51,-23,2,-1},
        {223,7,8,-11,5,-99,2,3,-4},
        {2,51,-23,-23,6,3,2,4,5},
        {5,-99,2,-1,32,2,5,-99,2},
        {6,3,3,-4,2,-1,6,3,3},
        {32,2,4,5,3,-4,2,-1,4},
        {4,4,23,6,2,-1,3,-4,34},
        {78,32,1,7,3,-4,-23,-23,6},
    };

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 9; j++) {
            cout << twoDimension[i][j] << " ";
        }
        cout << "\n";
    }

    numberGame(twoDimension);

    return 0;
}