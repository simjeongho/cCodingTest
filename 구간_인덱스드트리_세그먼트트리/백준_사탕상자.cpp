#pragma warning(disable:4996)
/*
	입력 
	인덱스드 트리로 푼다. 
	Top - down 방식으로 query한다. 
*/
#include <iostream>
#include <cstdio>
#define SIZE_TR 2097152 // 트리 사이즈는 MAX * 2
#define OFFSET 1048576 // 백만을 넘는 최초의 2의 제곱 수
#define ll long long
using namespace std;

int n; // 사탕 상자에 손을 댄 횟수
int comm; // 1인지 2인지
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