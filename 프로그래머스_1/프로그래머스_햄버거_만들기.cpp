#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int cnt = 1;
    string s;
    int size = ingredient.size();
    for (int i = 0; i < size; i++) {
        if (s.length() < 3) {
            s += to_string(ingredient[i]); 
        }
        else {
            s += to_string(ingredient[i]);
            
            if (s.substr(s.length() - 4) == "1231") {
                answer++;
                s.erase(s.end()-4, s.end());
            }
        }
    }
    return answer;
}
int main() {
    vector <int> ingredient = { 2,1,1,2,3,1,2,3,1 };
    vector <int> ingredient1 = { 1,3,2,1,2,1,3,1,2 };
    cout << solution(ingredient) << "\n";
    return 0;
}