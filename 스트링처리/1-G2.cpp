#include <iostream>
using namespace std;
int n;
string pattern;
string filename;
string pre;
string back;
int main() {
    cin >> n;
    cin >> pattern;
    for(int i = 0; i < pattern.size(); i++) {
        if(pattern[i] == 42)
        {
            pre = pattern.substr(0, i-1);
            back = pattern.substr(i+1, pattern.size() - (i + 1));
        }
    } // 접두사 접미사 추출
    for(int i = 0; i < n; i++){
        cin >> filename;
        if(filename.substr(0, pre.size()) == pre && filename.substr(filename.size() - back.size()) == back) cout << "DA";
        else cout << "NE";

    }
    return 0;
}