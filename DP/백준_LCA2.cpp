#pragma warning (disable : 4996)
/*
	핵심 아이디어
	x의 2^k 번째 조상을 parent[x][k]로 설정한다.
	
	k = 0이라면 바로 위의 부모를 의미하고
	k = 1이라면 2번째 부모를 의미한다.

	parent[x][1] = parent[parent[x][0]][0] -> [x][1]은 2번째 부모를 의미하므로 parent[parent[x][0]][0] 부모의 바로 위 부모를 의미한다.
	parent[x][2] = parent[parent[x][1]][1] -> [x][2]는 x의 4번째 위 부모를 의미하므로 parent[parent[x][1]][1]은 2 * 2 4번째가 된다.
	즉 점화식은 parent[x][k] = parent[parent[x][k-1]][k-1] 이된다. 
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#define HEIGHTMAX 18
#define MAX 100002
using namespace std;
int N; // 노드의 개수
int M; // 최소 공통 조상 알고 싶은 쌍의 개수
int parent[MAX][HEIGHTMAX + 1]; // 부모 저장 dp배열
int depth[MAX]; // depth를 나타내는 배열
vector<int> AL[MAX];
int ans;
void input() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int p, c;
		scanf("%d %d", &p,&c);
		AL[p].push_back(c); // 부모와 연결된 자식 노드들 저장
		AL[c].push_back(p); // 방향성이 없다.
	}
}
void makeTreeDfs(int curr) {
	for (auto next : AL[curr]) {
		if (!depth[next]) {
			parent[next][0] = curr; // 바로 위 부모는 현재 노드
			depth[next] = depth[curr] + 1;
			makeTreeDfs(next);
		}
	}
}

void makeParent() {
	for (int j = 0; j < HEIGHTMAX-1; j++) {
		for (int i = 1; i <= N; i++) {
			int p = parent[i][j];
			//점화식 parent[x][k] = parent[parent[x][k-1]][k-1];
			parent[i][j + 1] = parent[p][j];
		}
	}
}

void lca2(int l, int r) {
	if (depth[l] < depth[r]) swap(l, r); // depth가 더 큰 것을 항상 왼쪽에 둔다. 
	int diff = depth[l] - depth[r]; // 두 depth의 차이
	int move = 0;
	int cmp = 1;
	while (diff) {
		if (cmp & diff) {
			l = parent[l][move];
		}
		diff >>= 1;
		move++;
	} // 같은 층으로 만든다. 
	// 같은 층으로 만들었다는 것은 루트까지 같은 depth에 올라갈 수 있다는 뜻
	if (l != r) {
		//가장 높이 존재하는 부모부터 비교한다. 
		//만약 다르다면 그 다른 노드의 부모노드가 최소 공통 조상이다. 
		for (int j = HEIGHTMAX - 1; j >= 0; j--) {
			if (parent[l][j] != parent[r][j]) {
				l = parent[l][j];
				r = parent[r][j]; // 각각 그 다른 노드를 올라간다. 
			}
		}
		ans = parent[l][0]; // 정답은 그 달라진 노드의 바로 위 부모에 해당한다. 
	}
	else {
		ans = l; // 만약 그대로라면 그냥 바로 l
	}
	printf("%d\n", ans);

}

void sol() {
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		lca2(l, r);
	}
}



int main() {
	input();
	depth[1] = 1;
	makeTreeDfs(1); // 루트는 1번이다. 
	makeParent(); //parent 배열을 만들어준다. 
	sol();
	return 0;
}