#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct User {
    int cnt = 0;
    vector<string> v;
};

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, User> mp;
    vector <string> warn;
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    for (string b : report) {
        cout << b << "\n";
    }
    for (int i = 0; i < report.size(); i++) {
        int j = 0;
        string temp = "";
        string temp2 = "";
        while (report[i][j] != ' ') {
            j++;
        }
        temp = report[i].substr(0, j);
        j++;
        temp2 = report[i].substr(j, report[i].size());

        mp[temp].v.push_back(temp2);
        mp[temp2].cnt++;
        if (mp[temp2].cnt == k) warn.push_back(temp2);
    }
    for (int i = 0; i < id_list.size(); i++) {
        int c = 0;
        for (string a : mp[id_list[i]].v) {
            for (string b : warn) {
                if (b == a) {
                    c++;
                    break;
                }
            }
        }
        answer.push_back(c);
    }
    for (int a : answer) {
        cout << a << " ";
    }
    return answer;
}

int main() {
    vector <string> id_list = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report = { "muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi" };

    vector<string> id_list1 = { "con", "ryan" };
    vector<string> report1 = { "ryan con", "ryan con", "ryan con", "ryan con" };

    vector<string> id_list2 = { "muzi", "frodo", "con", "ryan" };
    vector<string> report2 = { "muzi frodo", "muzi con", "muzi ryan", "muzi con"};
    solution(id_list2, report2, 1);
}