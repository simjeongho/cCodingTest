#include <stdc++.h>
#include <iostream>
using namespace std;
int cnt[26];
int main(){

    string str;
    cout << "enter your string" << endl;
    cin >> str;
    for(char a : str) {
        cnt[a - 'a']++;
    }
    cout << str << endl;
    for(int i = 0 ; i < 26; i++) {
        cout << cnt[i] << " ";
    }

    string str2;
    cout << "enter your second string";
    cin >> str2;
    for(char b : str2){
        cout << b << " ";
    }
    return 0;
}