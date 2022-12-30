#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = 0;
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 97 and s[i] <= 122) {
            switch (s[i]) {
                case 'z':
                    s.replace(i, 4, "0");
                    break;
                case 'o':
                    s.replace(i, 3, "1");
                    break;
                case 't':
                    if (s.substr(i, 3) == "two") {
                        s.replace(i, 3, "2");
                        break;
                    }
                    else {
                        s.replace(i, 5, "3");
                        break;
                    }
                case 'f' :
                    if (s.substr(i, 4) == "four") {
                        s.replace(i, 4, "4");
                        break;
                    }
                    else {
                        s.replace(i, 4, "5");
                        break;
                    }
                case 's' :
                    if (s.substr(i, 3) == "six") {
                        s.replace(i, 3, "6");
                        break;
                    }
                    else {
                        s.replace(i, 5, "7");
                        break;
                    }
                case 'e': {
                    s.replace(i, 5, "8");
                    break;
                }
                case 'n': {
                    s.replace(i, 4, "9");
                }

           }
        }
    }
    answer = stoi(s);
    return answer;
}

int main() {
    solution("1eight2");
    solution("one4seveneight");
    solution("2three45sixseven");
}