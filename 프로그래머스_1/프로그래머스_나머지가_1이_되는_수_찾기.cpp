#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    if (n % 2) {
        answer = 2;
    }
    else {
        int temp = 2;
        while ((n-1) % temp != 0) {
            temp++;
        }
        answer = temp;
    }
    return answer;
}

int main() {
    solution(10);
    solution(12);

    return 0;
}