//1 -C 2979번 - 트럭 주차
//1분에 한 대당 A원을 내야한다. 
// 두대 이상이면 1분에 한대당 B원을 내야한다.
#include <iostream>
using namespace std;

int main() {
    int cnt;
    int minute;
    int cost;
    int a, b;
    if( cnt == 1)
    {
        cost =  a * minute;
    }
    else {
        cost = cnt * b * minute;
    }

    cout  << cost << " ";
    return 0;
}