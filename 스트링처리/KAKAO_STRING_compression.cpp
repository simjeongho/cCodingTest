#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int m = s.size() / 2;
    string temp;
    string copy = s;
    int si = 1;
    int minlength = copy.length();
    for (int i = 1; i <= m; i++)
    {
        temp = s.substr(0, i);
        for (int j = i; j <= copy.size(); j += i) {
            if (temp == copy.substr(j, i)) {
                si++;

            }
            else {
                if (si > 1) {
                    copy.replace(j - (si * i), (si - 1) * i, to_string(si));

                    j = j - ((si - 1) * i) + to_string(si).size();
                }
                si = 1;
                temp = copy.substr(j, i);


            }


        }
        cout << "i: " << i << " copy: " << copy << "\n";
        if (minlength > copy.length()) minlength = copy.length();

        copy = s;

    }
    cout << "minlength: " << minlength << "\n";
    return minlength;
}

int main() {
    //solution("aabbacccc");
    cout << "\n";
    //solution("aabbaccc");
    //solution("ababcdcdababcdcd");

    //solution("abcabcdede");

   // solution("abcabcabcabcdededededede");

    //solution("xababcdcdababcdcd");
    //solution("ababdababdacdcdacdcddededdeded");
    solution("aaaaaaaaaaaabcd");
    solution("xxxxxxxxxxyyy");
    solution("abcabcabcdabcfabcabcabczabcabcdddabc");
    solution("aababa");
    solution("aaaaaaaaaab");

    return 0;
}