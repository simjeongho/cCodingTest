#include <string>
#include <vector>
#include <math.h>
#include <typeinfo>
using namespace std;

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; i++) {
        if (floor(sqrt(i)) == sqrt(i)) {
            answer -= i;
        }
        else answer += i;
    }
    return answer;
}

int main() {
    solution(13, 17);
}