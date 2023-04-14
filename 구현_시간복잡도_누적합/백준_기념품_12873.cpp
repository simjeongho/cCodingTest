#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
int n;
int main() {
    scanf(" %d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    auto it = a.begin();
    for (int i = 1; i < n; i++) {
        ll num = ((ll)i * i * i - 1) % a.size();
        for (int j = 0; j < num; j++) {
            it++;
            if (it == a.end()) it = a.begin();
        }
        it = a.erase(it);
        if (it == a.end()) it = a.begin();
    }
    printf("%d\n", a[0]);
}