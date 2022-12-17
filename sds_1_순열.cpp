#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int testCount = 0;
    cin >> testCount; //전체 테스트 횟수 입력
    int curIndex = 0;
    int n; // 숫자 개수
    //int result=0;
    int count = 0;
    for (curIndex; curIndex < testCount; curIndex++) {
        cin >> n;// 입력 받을 숫자 개수 입력
        vector <int> v(n);
        vector <int> v2;
        for (int j = 0; j < n; j++) {
            cin >> v[j];// 숫자 입력 
        }
        sort(v.begin(), v.end());
        do {

            for (int i = 0; i < n; i++) {

                if (i == n - 1) {
                    if (sqrt(v[i] + v[0]) == int(sqrt(v[i] + v[0]))) {
                        count++;
                    }
                }
                else {
                    if (sqrt(v[i] + v[i + 1]) == int(sqrt(v[i] + v[i + 1]))) {
                        count++;
                    }
                }
            }
            v2.push_back(count);
            count = 0;
        } while (next_permutation(v.begin() + 1, v.end()));//(고리의 총 개수==(n-1)!) 한 개 고정 후 순열 돌리기 
        int max = *max_element(v2.begin(), v2.end());

        cout << "#" << curIndex + 1 << " " << max << "\n";
    }
    return 0;
}
