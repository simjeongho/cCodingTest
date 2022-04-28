//백준 9996
#include <iostream>
#include <string>
using namespace std;
int n; // 파일 개수
bool t;
string filename;
int main() {
    cin >> n;
    for(int u = 0; u < n; u++) {
        cout << "enter your filename";
        cin>> filename;
        if(filename.size() > 100) break;
        for(int i = 0; i < filename.size(); i++)
        {
            if(filename[i] > 122 || filename[i] < 97)
            {
                cout << "";
                t = false;
            }
            else t=true;
        }
        if(t)
        {
            if(filename.front() == 'a' && filename.back() == 'd')
            {
                cout  << "DA" << endl;
            }
            else cout << "NE" << endl;
        }
        }
    
    
}