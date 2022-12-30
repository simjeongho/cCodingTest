#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    map<int, int> mp, mp1;
    vector<int> v;
    v.clear();
    for (char a : X) {
        mp[a]++;
    }
    for (char b : Y) {
        mp1[b]++;
    }
    for (int i = 48; i < 58; i++) {
        int temp = 0;
        if (mp[i] != 0 && mp1[i] != 0) {
            temp = i;
            for (int j = 0; j < min(mp[i], mp1[i]); j++) {
                v.push_back(temp);
            }
        }
    }
    sort(v.begin(), v.end(), greater<int> ());
    if (v.size() == 0) {
        answer =  "-1";
        return answer;
    }
    if (v[0] == 48) {
        answer = "0";
        return answer;
    }
    for (int i = 0; i < v.size(); i++) {
        answer += v[i];
    }
    return answer;
}

int main() {
    /*solution("12321", "42531");
    solution("5525", "1255");*/
    //solution("100", "2345");
    cout << solution("100", "203045") << "\n";
}