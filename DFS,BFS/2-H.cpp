#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

string password = "";
bool vowel = 0;
bool seq = 0;
int count[26];
stack<char> charStack;
void prejudicePasword (string str) {
    for(char a : str) {
        if(a == 97 || a == 101 || a == 105 || a == 111 || a == 117 ) {
            vowel = 1;
        }
    }
    charStack.push(str[0]);
    for(char i = str[1]; i < str.size(); i++) {
        if(charStack.top() == i) charStack.push(i);
        else charStack.pop();
        charStack.push(i);

        if(charStack.size() >= 3) {
            seq = 0; break;
        }
        // else if(charStack.size() == 2 && charStack.top() != 'e') {
        //     seq =0 ; break;
        // }
        else {
            seq = 1;
        } 
    }
}
void print() {
    if(vowel == 1 && seq == 1)
    {
        cout << "it is acceptable" << endl;
    }
    else cout << "it is unacceptable" <<endl;
}
int main() {

    while(password != "end") {
        seq = 0;
        vowel = 0;
        cin >> password;
        prejudicePasword(password);
        cout << "vowel:" << vowel << "seq:" << seq << endl;
        print();
    }

}