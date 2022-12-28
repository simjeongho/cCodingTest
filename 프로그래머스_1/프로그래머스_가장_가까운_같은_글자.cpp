#include <string>
#include <vector>
#include <iostream>
using namespace std;
string s;
int ch[26];
vector<int> solution(string s) {
    vector<int> answer;
    for (int i = 0; i < s.size(); i++) {
        if (ch[s[i] - 97] == 0) {
            answer.push_back(-1);
            ch[s[i] - 97] = i + 1;
        }
        else {
            answer.push_back(i - ch[s[i] - 97] + 1);
        }
        ch[s[i] - 97] = i+1;
    }
    cout << "[";
    for (int i = 0; i < answer.size(); i++) {
        if (i != answer.size() -1) cout << answer[i] << ",";
        else cout << answer[i];
    }
    cout << "]";
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    solution(s);
    return 0;
}