#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    int arr[10] = {0};
    for (int a : numbers) {
        arr[a]++;
    }
    for (int i = 0; i < 10; i++) {
        if (arr[i] == 0) {
            answer += i;
        }
    }
    answer++;
    cout << answer << "";
    return answer;
}

int main() {
    vector<int> numbers = { 5,8,4,0,6,7,9 };
    solution(numbers);
}