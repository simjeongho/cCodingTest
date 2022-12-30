#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string temp = "";
    string temp2 = "";
    for (int i = 0; i < food[0]; i++) {
        answer += "0";
    }
    for (int i = 1; i < food.size(); i ++) {
        for (int j = 0; j < food[i] / 2; j++) {
            temp = to_string(i) + temp;
            temp2 += to_string(i);
        }
    }
    answer = temp2 + answer;
    answer += temp;
    return answer;
}

int main() {
    vector <int> food = { 1,7,1,2 };
    cout << solution(food) << "\n";
}