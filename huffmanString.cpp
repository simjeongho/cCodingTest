#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;
struct huffmanNode {
    string a;
    int fre;
    huffmanNode* left;
    huffmanNode* right;
};

struct cmp {
    bool operator()(huffmanNode* a, huffmanNode* b) {
        return a->fre > b->fre;
    }
};


class HuffmanTree {
private:
    huffmanNode* root = nullptr;
    unordered_map <string, int> ascii;
    unordered_map<string, string> code;
    priority_queue<huffmanNode*, vector<huffmanNode*>, cmp> pq;
    string text;
public:
    ~HuffmanTree() {
        releaseTree(root);
        root = nullptr;
        while (!pq.empty()) pq.pop();
    }

public:
    void Start() {
        //ifstream file("test.txt");
        //while (getline(file, text)) {
        //    cout << text << "\n";
        //    for (char a : text) {
        //        //ascii[a - 'a'] ++;
        //        /*ascii[a].fre++;
        //        ascii[a].a = a;*/
        //        ++ascii[a];
        //    }
        //}
        // 
        ascii.insert(make_pair("SIM", 27));
        ascii.insert(make_pair("ABC", 12));
        ascii.insert(make_pair("ABCC", 7));
        ascii.insert(make_pair("AB", 19));
        ascii.insert(make_pair("A", 35));
        ascii.insert(make_pair("B", 40));
        ascii.insert(make_pair("BABA", 15));
        //pq에 삽입
        for (const auto iter : ascii) {
            huffmanNode* newhuffman = new huffmanNode;
            newhuffman->left = nullptr;
            newhuffman->right = nullptr;
            newhuffman->a = iter.first;
            newhuffman->fre = iter.second;
            pq.push(newhuffman);
        }
        MakeTree();
        string tmp = "";
        FindTree(root, tmp);
    }
    void showCode() {
        for (auto it = code.begin(); it != code.end(); ++it)
        {
            cout << it->first << " : " << it->second << "\n";
        }
    }
private:
    void MakeTree() {
        int lim = pq.size() - 1;
        for (int i = 0; i < lim; i++) {
            huffmanNode* p = pq.top();
            pq.pop();
            huffmanNode* q = pq.top();
            pq.pop();
            huffmanNode* r = new huffmanNode;
            r->left = p;
            r->right = q;
            r->fre = p->fre + q->fre;
            r->a = "";
            pq.push(r);
            cout << "Make Tree시작" << r->left->a << r->left->fre << " " << r->right->a << r->right->fre << "\n";
            cout << "r->a : " << r->a << "r=>fre : " << r->fre << "\n";
        }
        root = pq.top();
        cout << "top is" << root->a << " " << root->fre << "\n";
    }

    void FindTree(huffmanNode* p, string str) {
        if (p == nullptr) return;
        FindTree(p->left, str + '0');
        FindTree(p->right, str + '1');
        if (p->a != "")
        {
            cout << str << "\n";
            //code map에 집어 넣기 
            code[p->a] = str;
        }
    }

    void releaseTree(huffmanNode* p)
    {
        if (p == nullptr) return;
        releaseTree(p->left);
        releaseTree(p->right);
        delete p;
        p = nullptr;
    }



};
int main() {

    HuffmanTree T;
    T.Start();
    T.showCode();
    return 0;
}