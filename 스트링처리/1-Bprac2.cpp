#include <iostream>
using namespace std;

int main() {
    string str;
    cout << "enter your string" << endl;
    cin >>str;

    for(char b: str )
    {
        cout << b <<" "; 
    }
    return 0;
}