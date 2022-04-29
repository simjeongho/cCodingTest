#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int M;
int N;
int Next[50];
string str;
string para;
void IninNext(string p) {
    M = p.size();
    int i, j;
    Next[0] = -1;
    for (i = 0, j = -1; i < M; i++, j++)
    {
        Next[i] = j;
        while (j >= 0 && p[i] != p[j]) {
            j = Next[j];
        }
    }
}

int KMP(string p, string text) {
    int i = 0;
    int j;
    M = p.size();
    N = text.size();
    IninNext(p);
    while (1) {
        for (i, j = 0; j < M && i < N; i++, j++) {
            while (j >= 0 && text[i] != str[j]) {
                j = Next[j];
            }
        }
        if (j == M) {
            cout << "패턴이 발생한 위치 " << i - M << endl; 
            i = i;
        }
        else {
            cout << "탐색 종료" << endl;
            return i;
        }
        if (i >= N) {
            cout << "탐색 종료" << endl;
            break;
        }
    } 
}


int main() {
    cout << "enter your text" << endl;
    getline(cin, para);
    //para.erase(remove(para.begin(), para.end(), ' '), para.end());
    cout << "enter your pattern" << endl;
    getline(cin, str);

    KMP(str, para);

    /*for (int i = 0; i < str.size(); i++) {
        cout << Next[i] << " ";
    }*/


    return 0;
}
