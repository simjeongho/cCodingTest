#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using naemspace std;

int n; // 줄의 개수 
string ret;
string s;
void go() {
    if(ret.size()){
        while(1){
            if(ret.front == "0") ret.erase(ret.begin());
            else break;
        }
        if(ret.size() == 0) ret = "0";
        v.push_back(ret);
    }
}

bool cmp(string a, string b) {
    if(a.size()== b.size()) return a<b;
    return a.size() < b.size();
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i ++ ){
        cin >> s;
        ret = "";
        for(int j = 0; j  < s.size(); j++) {
            if(s[j] < 58) ret += s[j];
            else go();
        }
        go();
    }
    return 0;
}