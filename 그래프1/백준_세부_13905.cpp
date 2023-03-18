#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int s, e;

vector<pair<pair<int, int>, int> > edges;
vector<int> parents;
vector<vector<pair<int, int> > > graph;


bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second > b.second;
}

int get_parent(int a) {
    if (parents[a] == a) return a;
    return parents[a] = get_parent(parents[a]);
}

void union_parents(int a, int b) {

    a = get_parent(a);
    b = get_parent(b);

    if (a > b) parents[a] = b;
    else parents[b] = a;
}

void kruskal() {

    for (int i = 1; i <= n; i++) parents[i] = i;
    sort(edges.begin(), edges.end(), cmp);

    for (int i = 0; i < edges.size(); i++) {
        if (get_parent(edges[i].first.first) != get_parent(edges[i].first.second)) {

            union_parents(edges[i].first.first, edges[i].first.second);

            // 최대값으로 연결된 스패닝 트리  
            graph[edges[i].first.first].push_back({ edges[i].first.second, edges[i].second });
            graph[edges[i].first.second].push_back({ edges[i].first.first, edges[i].second });
        }
    }
}

// 최대값 스패닝 트리에서 BFS로 탐색하여 최소값만 저장하기
// DP처럼 이전 값과 현재 값을 비교하여 최소값만 저장  
void find_path() {
    vector<int> costs;
    vector<int> isVisited;
    isVisited.resize(n + 1);
    costs.resize(n + 1);
    for (int i = 1; i <= n; i++) costs[i] = 987654321;

    queue<int> q;
    q.push(s);
    isVisited[s] = 1;
    costs[s] = 987654321;

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        for (int i = 0; i < graph[here].size(); i++) {
            int next = graph[here][i].first;
            int next_cost = graph[here][i].second;

            if (isVisited[next]) continue;
            isVisited[next] = 1;

            costs[next] = min(costs[here], next_cost);
            q.push(next);
        }
    }

    // 못 갈 수도 있는 경우 고려해야 한다. 
    if (costs[e] == 987654321) cout << 0 << "\n";
    else cout << costs[e] << "\n";
}


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    cin >> s >> e;

    parents.resize(n + 1);
    graph.resize(n + 1);

    int u, v, c;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        edges.push_back({ {u, v}, c });
    }

    kruskal();
    find_path();
}
