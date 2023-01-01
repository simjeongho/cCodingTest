#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";
    string temp = "";
    string removes = "~!@#$%^&*()=+[{]}:?,<>/";
    bool flag = 0;
    for (char a : removes) {
        new_id.erase(remove(new_id.begin(), new_id.end(), a), new_id.end());
    }
    if (new_id.size() == 0) {
        answer = "aaa";
        return answer;
    };
    temp = new_id[0];
    for (int i = 0; i < new_id.size(); i++) {
        while (new_id[0] == '.') {
            new_id.erase(0, 1);
            i = 0;
        }
        if (new_id.size() == 0) {
            answer = "aaa";
            return answer;
        };
        if (new_id[i] >= 97 && new_id[i] <= 122) {
            temp = new_id[i];
            continue;
        }
        else if (new_id[i] >= 65 && new_id[i] <= 90) {
            new_id[i] += 32;
            temp = new_id[i];
            continue;
        }
        else if (new_id[i] == '.' || new_id[i] == '-' || new_id[i] == '_') {
            temp = new_id[i];
            if (temp == "." && new_id[i] == '.') {
                int j = i;
                while (new_id[j] == '.') {
                    j++;
                }
                new_id.erase(i, j - i - 1);
                continue;
            }
        }
    }
    while (flag == 0) {
        if (new_id[new_id.size() - 1] == '.') {

            new_id.erase(new_id.end() - 1);

        }
        else {
            flag = 1;
        }
    }
    if (new_id.size() >= 16) {
        new_id.erase(15);
        int flag1 = 0;
        while (flag1 == 0) {
            if (new_id[new_id.size() - 1] == '.') {
                new_id.erase(new_id.end() - 1);
            }
            else {
                flag1 = 1;
            }
        }
    }
    else if (new_id.size() == 0) {
        answer = "aaa";
    }
    else if (new_id.size() <= 2) {
        int t = new_id.size() - 1;
        while (new_id.size() != 3) {
            new_id += new_id[t];
        }
        answer = new_id;
        return answer;
    }
    answer = new_id;
    return answer;
}

int main() {
    //solution("...!@BaT#*..y.abcdefghijklm");
    //solution("abcdefghijklmn.p");
    solution("=.=");
    //solution("z-+.^,");
    return 0;
}