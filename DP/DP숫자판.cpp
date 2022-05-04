#include <iostream>

using namespace std;

#define col 9
#define row 8
void numberGame(int twoDimension[][col]) {
    for (int i = 1; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == 0) {
                twoDimension[i][j] += (twoDimension[i - 1][j] < twoDimension[i - 1][j + 1] ? twoDimension[i - 1][j + 1] : twoDimension[i - 1][j]);//���� ���� ���� �� [i-1][j] == �ٷ� �� < [i-1][j+1] == ������ �밢�� ����� �� ū �� �����ش�. �� ������ ����Ѵ�. 
                cout << "if : " << twoDimension[i][j] << "\n";
            }
            else if (j == col -1) {
                twoDimension[i][j] += (twoDimension[i - 1][j - 1] < twoDimension[i - 1][j] ? twoDimension[i - 1][j] : twoDimension[i - 1][j - 1]); //���� ������ ���� ��[i-1][j-1] = ���� �밢�� ��  < [i-1][j]�ٷ� ����� �� ū �� �����ش�. �� ������ ����Ѵ�. 
                cout << "else if  : " << twoDimension[i][j] << "\n";
            }
            else {
                //���� �߰��̶�� ���� �밢�� ���� �ٷ� ���� �� �ٷ� ���� ������ �밢�� ���� �� ���� �밢�� ���� �� ũ�ٸ� ���� �밢���� ������ �밢���� ��  ���� ū �� �����ش�. 
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