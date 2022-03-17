//백준 1159번
#include <iostream>
#include <string>
using namespace std;
int cnt[26];
string player[150];
int main() {
    player[0] = "jeongho";
    player[1] = "daeun";
    for(int i = 0; i < 150; i ++)
    {
        for(char a = player[i].at(0) ; a < 1; a++)
        {
            cnt[a - 'a']++;
        }
    }

    for(int i = 0 ; i < 26; i++)
    {
        cout << cnt[i] << " ";
    }
    return 0;
}