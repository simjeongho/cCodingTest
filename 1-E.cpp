//백준 1159번
#include <iostream>
#include <string>
using namespace std;
int cnt[26];
int n;
string player;
string ret;
int main() {

    cout << "enter your player number" << endl;
    cin >> n;
    for(int i= 0; i < n ; i ++ )
    {
        cout << "enter your player name" << endl;
        cin >> player;
        cnt[player[0] - 'a']++;
    }
    
    for(int i = 0; i < 26; i ++ )
    {
        if(cnt[i] >= 5)
        {
            ret += i+ 'a';
        }
    }
    if(ret.size()) cout << ret << " ";
    else cout << "PREDAJA" << endl;
    return 0;
}