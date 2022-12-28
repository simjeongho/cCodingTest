#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    string ex[4] = { "aya", "ye", "woo", "ma" };
    for (string a : babbling) {
        int warn = 5;
        while (1) {
        if (a.substr(0, 2) == "ye") {
            if (warn == 1) break;
            a.erase(0, 2);
            
            if (a.length() == 0) {
                answer++;
                break;
            }
            warn = 1;
        }
        else if (a.substr(0, 2) == "ma") {
            if (warn == 3) break;
            a.erase(0, 2);
            
            if (a.length() == 0) {
                answer++;
                break;
            }
            warn = 3;
         }
        else if (a.substr(0, 3) == "aya") {
            if (warn == 0) break;
            a.erase(0, 3);
            
            if (a.length() == 0) {
                answer++;
                break;
            }
            warn = 0;
        }
        else if (a.substr(0, 3) == "woo") {
            if (warn == 2) break;
            a.erase(0, 3);
            
            if (a.length() == 0) {
                answer++;
                break;
            }
            warn = 2;
        }
        else {
            
           break;
        }        
        }
    }
    return answer;
}

int main() {
    vector<string> babbling = { "aya", "yee", "u", "maa" };
    vector<string> babbling1 = { "ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"};
    cout << solution(babbling1) << "\n";

    return 0;
}