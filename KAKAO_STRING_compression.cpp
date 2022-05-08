#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> v;

int solution(string s) {
    int answer = 0;
    string copy = s;
    int t = 0;
    int u = 0;
    int m = s.size() / 2;
    for (int i = 1; i <= m; i++) {
        string first = s.substr(0, i);
        v.push_back(first);
        while (u < s.size() - i) {
            string temp = s.substr(u + i, i);
            cout <<"temp:" << temp << "\n";
            if (v.back() == temp) v.push_back(temp);
            else {
                int size;
                size = v.size();
                if(size >1)copy.replace(u, i, to_string(size)); 
                cout << " string! :" << copy << "\n";
                    v.clear();
                    v.push_back(temp);
            }
            cout << "vector! =============================\n";
            for (int i = 0; i < v.size(); i++) {
                
                cout << "v:" << v[i] << "\n";
            }
            u = u+i;     
        }
        u = 0;
    }
    return answer;
}

int main() {
    solution("aabbaccc");

    return 0;
}