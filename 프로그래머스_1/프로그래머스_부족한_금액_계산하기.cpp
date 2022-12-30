#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    int temp = 0;
    temp = price + price * count;
    bool flag = 0;
    for (int i = 1; i <= count / 2; i++) {
        answer += temp;
        if (money <= answer and flag ==0) {
            answer -= money;
            flag = 1;
        }
    }
    if (count % 2) {
        answer += price * ((count / 2) + 1);
    }
    return answer;
}

int main() {

}