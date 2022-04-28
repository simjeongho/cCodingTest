//백준 10988
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string str;
string temp;
int main() {
    cout << "enter your string" << endl;
    cin >> str;
    temp = str;
    reverse(str.begin(), str.end());//void 형이다. 
    if(str == temp)
    {
        cout << "1" << endl;
    }
    else{
        cout << "0" << endl;
    }
    return 0;
    
}