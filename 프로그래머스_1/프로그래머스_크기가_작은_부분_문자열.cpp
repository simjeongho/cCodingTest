#include <string>
#include <vector>
#include <iostream>

using namespace std;
string t, p;
int solution(string t, string p) {
    int answer = 0;
    for (int i = 0; i <= t.size() - p.size(); i++) {
        string temp;
        for (int j = 0; j < p.size(); j++) {
            temp += t[i];
        }
        if (stoi(temp) <= stoi(p)) answer++;
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t >> p;
    cout << solution(t, p) << "\n";
}