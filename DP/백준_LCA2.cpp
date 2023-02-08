#pragma warning (disable : 4996)
/*
	�ٽ� ���̵��
	x�� 2^k ��° ������ parent[x][k]�� �����Ѵ�.
	
	k = 0�̶�� �ٷ� ���� �θ� �ǹ��ϰ�
	k = 1�̶�� 2��° �θ� �ǹ��Ѵ�.

	parent[x][1] = parent[parent[x][0]][0] -> [x][1]�� 2��° �θ� �ǹ��ϹǷ� parent[parent[x][0]][0] �θ��� �ٷ� �� �θ� �ǹ��Ѵ�.
	parent[x][2] = parent[parent[x][1]][1] -> [x][2]�� x�� 4��° �� �θ� �ǹ��ϹǷ� parent[parent[x][1]][1]�� 2 * 2 4��°�� �ȴ�.
	�� ��ȭ���� parent[x][k] = parent[parent[x][k-1]][k-1] �̵ȴ�. 
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#define HEIGHTMAX 18
#define MAX 100002
using namespace std;
int N; // ����� ����
int M; // �ּ� ���� ���� �˰� ���� ���� ����
int parent[MAX][HEIGHTMAX + 1]; // �θ� ���� dp�迭
int depth[MAX]; // depth�� ��Ÿ���� �迭
vector<int> AL[MAX];
int ans;
void input() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int p, c;
		scanf("%d %d", &p,&c);
		AL[p].push_back(c); // �θ�� ����� �ڽ� ���� ����
		AL[c].push_back(p); // ���⼺�� ����.
	}
}
void makeTreeDfs(int curr) {
	for (auto next : AL[curr]) {
		if (!depth[next]) {
			parent[next][0] = curr; // �ٷ� �� �θ�� ���� ���
			depth[next] = depth[curr] + 1;
			makeTreeDfs(next);
		}
	}
}

void makeParent() {
	for (int j = 0; j < HEIGHTMAX-1; j++) {
		for (int i = 1; i <= N; i++) {
			int p = parent[i][j];
			//��ȭ�� parent[x][k] = parent[parent[x][k-1]][k-1];
			parent[i][j + 1] = parent[p][j];
		}
	}
}

void lca2(int l, int r) {
	if (depth[l] < depth[r]) swap(l, r); // depth�� �� ū ���� �׻� ���ʿ� �д�. 
	int diff = depth[l] - depth[r]; // �� depth�� ����
	int move = 0;
	int cmp = 1;
	while (diff) {
		if (cmp & diff) {
			l = parent[l][move];
		}
		diff >>= 1;
		move++;
	} // ���� ������ �����. 
	// ���� ������ ������ٴ� ���� ��Ʈ���� ���� depth�� �ö� �� �ִٴ� ��
	if (l != r) {
		//���� ���� �����ϴ� �θ���� ���Ѵ�. 
		//���� �ٸ��ٸ� �� �ٸ� ����� �θ��尡 �ּ� ���� �����̴�. 
		for (int j = HEIGHTMAX - 1; j >= 0; j--) {
			if (parent[l][j] != parent[r][j]) {
				l = parent[l][j];
				r = parent[r][j]; // ���� �� �ٸ� ��带 �ö󰣴�. 
			}
		}
		ans = parent[l][0]; // ������ �� �޶��� ����� �ٷ� �� �θ� �ش��Ѵ�. 
	}
	else {
		ans = l; // ���� �״�ζ�� �׳� �ٷ� l
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
	makeTreeDfs(1); // ��Ʈ�� 1���̴�. 
	makeParent(); //parent �迭�� ������ش�. 
	sol();
	return 0;
}