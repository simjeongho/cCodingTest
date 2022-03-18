//백준 11655
#include <iostream>
#include <string>
using namespace std;
string input;

int main() {
    cout << "enter your string" << endl;
    getline(cin, input);
    for(int i = 0; i < input.size(); i++) {
        if(input[i] < 91 && input[i] > 64)
        {
            if(input[i] + 13 > 90)
            {
                input[i] = input[i] -13;
            }
            else input[i] += 13;
        }// 대문자 판별

        else if(input[i] > 96 && input[i] < 123)
        {
            if(input[i] + 13 > 122)
            {
                input[i] = input[i] -13;
            }
            else input[i] += 13;
        }// 소문자 판별 
    }
    cout << input;
    return 0;
}