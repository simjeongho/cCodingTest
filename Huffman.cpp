#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
#include <string>

using namespace std;
struct huffmanNode {
    char a;
    int fre;
    huffmanNode* left;
    huffmanNode* right;
};
huffmanNode ascii[127];
struct cmp {
    bool operator()(huffmanNode a, huffmanNode b) {
        return a.fre > b.fre;
    }
};
priority_queue<huffmanNode, vector<huffmanNode>, cmp> pq;
int main() {

    ifstream file("test.txt");
    string str;
    while (getline(file, str)) {
        cout << str << "\n";
        for (char a : str) {
            //ascii[a - 'a'] ++;
            ascii[a].fre ++;
            ascii[a].a = a;
        }
    }
    for (int i = 0; i < 127; i++) {
        cout << ascii[i].fre << " ";
    }
    cout << "\n";
    for (int i = 0; i < 127; i++) {
        pq.push(ascii[i]);
    }
    cout << pq.size() << "\n";
    /*cout << pq.top() << " ";
    pq.pop();
    cout << pq.top() << " ";
    pq.pop();
    cout << pq.top() << " ";
    pq.pop();*/
    while (pq.top().fre == 0) {
        pq.pop();
    }
    while (!pq.empty()) {
        cout << pq.top().a << " " << pq.top().fre << " ";
        pq.pop();
    }
    for (int i = 1; i < pq.size(); i++) {
        huffmanNode p = pq.top();
        pq.pop();
        huffmanNode q = pq.top();
        pq.pop();
        huffmanNode r;
        r.left = &p;
        r.right = &q;
        r.fre = p.fre + q.fre;
        pq.push(r);
    }

    /*while (!pq.empty()) {
        cout << pq.top().a << " " << pq.top().fre << " " ;
        pq.pop();
   }*/

    return 0;
}