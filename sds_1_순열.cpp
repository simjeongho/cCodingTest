#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int testCount = 0;
    cin >> testCount; //��ü �׽�Ʈ Ƚ�� �Է�
    int curIndex = 0;
    int n; // ���� ����
    //int result=0;
    int count = 0;
    for (curIndex; curIndex < testCount; curIndex++) {
        cin >> n;// �Է� ���� ���� ���� �Է�
        vector <int> v(n);
        vector <int> v2;
        for (int j = 0; j < n; j++) {
            cin >> v[j];// ���� �Է� 
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
        } while (next_permutation(v.begin() + 1, v.end()));//(���� �� ����==(n-1)!) �� �� ���� �� ���� ������ 
        int max = *max_element(v2.begin(), v2.end());

        cout << "#" << curIndex + 1 << " " << max << "\n";
    }
    return 0;
}
