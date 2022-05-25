#include <iostream>
using namespace std;

struct Thing {
    int weight, val;
};

int value[101][100001], n, k;
Thing thing[101];

int main() {
    cin >> n >> k;

    //물건들의 무게와 가치(w, v)를 입력받는다.
    for (int i = 1; i <= n; i++) {
        int w, v;
        cin >> w >> v;
        thing[i] = { w, v };
    }

    //다이나믹 프로그래밍
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int wi = thing[i].weight;
            int vi = thing[i].val;

            //i 번째 물체의 무게를 포함할 수 없는 경우
            if (wi > j) {
                value[i][j] = value[i - 1][j];
            }//i 번째 물체의 무게를 배낭의 용량(k)가 포함할 수 있는 경우
            else {
                value[i][j] = max(value[i - 1][j], vi + value[i - 1][j - wi]);
            }

        }
    }
    cout << value[n][k];
    return 0;
}