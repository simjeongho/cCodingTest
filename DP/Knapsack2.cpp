#include <iostream>
using namespace std;

struct Thing {
    int weight, val;
};

int value[101][100001], n, k;
Thing thing[101];

int main() {
    cin >> n >> k;

    //���ǵ��� ���Կ� ��ġ(w, v)�� �Է¹޴´�.
    for (int i = 1; i <= n; i++) {
        int w, v;
        cin >> w >> v;
        thing[i] = { w, v };
    }

    //���̳��� ���α׷���
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int wi = thing[i].weight;
            int vi = thing[i].val;

            //i ��° ��ü�� ���Ը� ������ �� ���� ���
            if (wi > j) {
                value[i][j] = value[i - 1][j];
            }//i ��° ��ü�� ���Ը� �賶�� �뷮(k)�� ������ �� �ִ� ���
            else {
                value[i][j] = max(value[i - 1][j], vi + value[i - 1][j - wi]);
            }

        }
    }
    cout << value[n][k];
    return 0;
}