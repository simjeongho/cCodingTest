#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N   1000000
#define SZ_TR   2097152

typedef long long ll;

int N, M, K;
int OFFSET = 1;
ll nos[MAX_N];
ll tree[SZ_TR];

void init() {
    while (OFFSET < N) OFFSET *= 2;
    cout << OFFSET << "\n";
    for (int i = 0; i < N; i++) tree[OFFSET + i] = nos[i];
    for (int i = N; i < OFFSET; i++) tree[OFFSET + i] = 0;
    for (int i = OFFSET - 1; i > 0; i--) tree[i] = tree[i * 2] + tree[i * 2 + 1];
    //for (int i = OFFSET - 1; i > 0; i--) tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}
ll query(int from, int to) {
    ll res = 0;
    from += OFFSET;     to += OFFSET;
    while (from <= to) {
        if (from % 2 == 1)    res += tree[from++];
        if (to % 2 == 0)     res += tree[to--];

        from /= 2;  to /= 2;
    }
    return res;
}
void update(int idx, ll val) {
    idx += OFFSET;
    tree[idx] = val;
    while (idx > 0) {
        idx /= 2;
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
}
int main() {

    int com;
    ll x, y;
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; i++) scanf("%lld", nos + i);
    init();
    for (int i = 0; i < N*4; i++) {
        cout << tree[i] << " ";
    }
    for (int i = 0; i < M + K; i++) {
        scanf("%d %lld %lld", &com, &x, &y);
        if (com == 1) update(x - 1, y);
        if (com == 2) printf("%lld\n", query(x - 1, y - 1));
    }

}