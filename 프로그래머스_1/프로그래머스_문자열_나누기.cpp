#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int solution(string s) {
    int answer = 1;
    int x = 1, x2 = 0;  
    int size = s.size();
    int j = 1;
    char t = s[0];
     while (j < size) {
        if (t == s[j]) x++;
        else x2++;
        if (x == x2) {
            j++;
           x = 1; x2 = 0;
           if (j == size) {
               
               break;
           }
           t = s[j];
           j++;
           answer++;
          
         }
         else j++;
       
      }
     
        return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string te = "";
    cin >> te;
    cout << solution(te) << "\n";
}

