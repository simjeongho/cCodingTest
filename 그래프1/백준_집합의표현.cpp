#pragma warning (disable:4996)
/*
	find(A)�� find(b)�� ���� ���� Ȯ���Ѵ�. 

*/
#include <cstdio>
#include <iostream>
#define MAX 1000000 + 2
using namespace std;
int n; // �鸸
int m; // �ʸ�
int id, first, second;
int parent[MAX];
int do_find(int x) {
	if (x == parent[x])return x;
	return parent[x] = do_find(parent[x]);
}

void do_union(int x, int y) {
	int px = do_find(x);
	int py = do_find(y);

	if (px > py) parent[px] = py;
	else if (px < py) parent[py] = px;
}


void sol(int id, int first, int second) {
	if (id == 0) {
		// �������� ����� �κ�
		do_union(first, second);
	}
	else {
		if (do_find(first) == do_find(second)) printf("YES\n");
		else printf("NO\n");
	}
}
void input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &id, &first, &second);
		sol(id, first, second);
	}
}
int main() {

	input();

	return 0;
}