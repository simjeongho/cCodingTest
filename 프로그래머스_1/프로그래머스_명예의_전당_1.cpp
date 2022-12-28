#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>
using namespace std;
vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>>pq;
    int cnt = 0;
    for (int a : score) {
        cnt++;
        if (cnt > k) {
            pq.pop();
            pq.push(a);
            answer.push_back(pq.top());
        }
        else {
            pq.push(a);
            answer.push_back(pq.top());
        }

    }

    return answer;
}