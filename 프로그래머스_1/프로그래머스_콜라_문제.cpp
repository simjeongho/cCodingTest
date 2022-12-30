#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while (1) {
        answer += (n / a) * b;
        n = (n / a) * b + (n % a);
        if (n < a) break;
    }

    return answer;
}

int main() {
    cout << solution(2, 1, 20) << "\n";
    cout << solution(3, 1, 20) << "\n";
}