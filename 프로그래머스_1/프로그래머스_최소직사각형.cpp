#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[0] > b[0];
}
bool compare2(vector<int> a, vector<int> b) {
    return a[1] > b[1];
}
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxR = 0;
    int maxC = 0;
    for (int i = 0; i < sizes.size(); i++) {
        int temp = 0;
        if (sizes[i][0] < sizes[i][1]) {
            
            temp = sizes[i][1];
            sizes[i].pop_back();
            sizes[i].insert(sizes[i].begin(), temp);
            
        }
    }
    
    sort(sizes.begin(), sizes.end(), compare);
    maxR = sizes[0][0];
    sort(sizes.begin(), sizes.end(), compare2);
    maxC = sizes[0][1];
    answer = maxR * maxC;
    return answer;
}

int main() {
    vector<vector<int>> sizes = { {60,50}, {30,70},{60,30} , {80,40} };
    vector<vector<int>> sizes1 = { {10,7},{12,3},{8,15},{14,7},{5,15} };
    
    solution(sizes1);

    return 0;
}