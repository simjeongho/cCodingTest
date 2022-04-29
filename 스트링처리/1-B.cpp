#include <iostream>
using namespace std;
int cnt[26];
string str;
int main()
{
    cout << "enter your string" << endl;
    cin >> str;

    for(char a : str){
        cnt[a - 'a']++;
    }
    for(int i = 0; i < 26; i ++) cout << cnt[i] << " ";

    return 0;
    
}