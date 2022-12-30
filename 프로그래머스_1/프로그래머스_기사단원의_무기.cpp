#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    map<int,int> mp;
    map<int, int>::iterator iter;
    for (int i = 1; i <= number; i++) {
        for (int j = i; j <= number; j += i) {
            mp[j]++;
        }
    }

    for (iter = mp.begin(); iter != mp.end(); iter++) {
        if (iter->second > limit) {
            answer += power;
        }
        else {
            answer += iter->second;
        }
    }
    return answer;
}

int main() {
    solution(5, 3, 2);
}