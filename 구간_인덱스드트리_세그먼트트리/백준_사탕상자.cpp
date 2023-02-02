#pragma warning(disable:4996)
/*
	�Է� 
	�ε����� Ʈ���� Ǭ��. 
	Top - down ������� query�Ѵ�. 
*/
#include <iostream>
#include <cstdio>
#define SIZE_TR 2097152 // Ʈ�� ������� MAX * 2
#define OFFSET 1048576 // �鸸�� �Ѵ� ������ 2�� ���� ��
#define ll long long
using namespace std;

int n; // ���� ���ڿ� ���� �� Ƚ��
int comm; // 1���� 2����
int b, c;
int Tree[SIZE_TR];
void update(int id, int cnt) {
	int idx = OFFSET + id - 1;
	Tree[idx] += cnt;
	while (idx > 1) {
		idx /= 2;
		Tree[idx] = Tree[idx * 2] + Tree[idx * 2 + 1];
	}
}

ll query(int rank, int id) {
	if (id >= OFFSET) {
		update(id-OFFSET +1, -1);
		return id - OFFSET + 1;
	}
	if (Tree[id * 2] >= rank) {
		return query(rank, id * 2);
	}
	else {
		return query(rank - Tree[id * 2], id * 2 + 1);
	}
}

void input() {
	scanf("%d", &n);
	for (int i = 0; i< n; i++) {
		scanf("%d", &comm);
		if (comm == 1) {
			scanf("%d", &b);
			printf("%lld\n" , query(b, 1));
		}
		else {
			scanf("%d %d", &b, &c);
			update(b , c);
		}
	}
}

int main() {
	input();

	return 0;
}