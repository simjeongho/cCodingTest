#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map <char, int> mp;
    string arr[4] = { "RT", "CF","JM", "AN" };
    for (int i = 0; i < choices.size(); i++) {
        if (choices[i] < 4) {
            mp[survey[i][0]] += 4 - choices[i];
        }
        else if (choices[i] > 4) {
            mp[survey[i][1]] += choices[i] - 4;
        }
    }
    for(string a : arr) {
        if (mp[a[0]] >= mp[a[1]]) {
            answer += a[0];
        }
        else {
            answer += a[1];
        }
    }
    return answer;
}

int main() {
    vector<string> survey = { "AN", "CF", "MJ", "RT","NA" };
    vector<int> choices = { 5,3,2,7,5 };


    cout << solution(survey, choices);
}