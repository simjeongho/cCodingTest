#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
string pattern;
int M;
int N;
int next[50]; 
char *str;
char *para;
void IninNext(char *p) {
    M = strlen(p);
    next[0] = -1;
    for(int i=0, int j = -1;i < M; i++, j++ )
    {
        next[i] = (p[i] == p[j]) ? next[j] : j;
        while(j >=0 && p[i] != p[j]){
            j = next[j];
        }
    }
}

int KMP(char *p, char *text) {
    int i, j;
    M = strlen(p);
    N = strlen(text);
    IninNext(p);
    for( i=0,  j = 0; j < m && i < n; i++, j++) {
        while(j >= 0 && text[i] != str[j]) {
            j = next[j];
        }
        if(j == M) return i - M;
        else return i;
    }
}

int main() {
    cout << "enter your text" << endl;
    cin >> para;
    cout << "enter your pattern" << endl;
    cin >> str;

    KMP(str, para);


    return 0;
}