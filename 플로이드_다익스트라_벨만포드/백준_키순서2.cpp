#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> f[501], s[501];
bool visit[501];
int N, M, cnt;

void dfs(vector<int> t[], int v) {
    visit[v] = true;

    for (int i = 0; i < t[v].size(); i++) {
        int next = t[v][i];

        if (visit[next]) continue;

        cnt++;
        dfs(t, next);
    }
}

void func() {
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        memset(visit, false, sizeof(visit));
        dfs(f, i);
        memset(visit, false, sizeof(visit));
        dfs(s, i);

        if (cnt == N - 1) ans++;
        cnt = 0;
    }

    cout << ans << '\n';
}

void input() {
    int u, v;
    cin >> N >> M;
    while (M--) {
        cin >> u >> v;
        f[u].push_back(v);
        s[v].push_back(u);
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    input();
    func();

    return 0;
}
