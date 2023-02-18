#pragma warning (disable: 4996)

#include <cstdio>
#define SIZE 1LL << 20 // 1048576
#define ll long long
using namespace std;
int offset = SIZE;
long long ITree[SIZE << 1];
int n;
void init() {
	
} // ��� �� ���ڷ� �����ϹǷ� init�Լ��� �ʿ����. 

void update(int idx, int val) {
	idx += offset;
	ITree[idx] += val; // ���� ������ �����ش�.
	while (idx > 0) {
		idx /= 2;
		ITree[idx] = ITree[idx * 2] + ITree[idx * 2 + 1];
		printf("ITree[%d]  = %d + %d\n", idx, ITree[idx * 2] + ITree[idx * 2 + 1]);
	}
} // ������Ʈ �Լ�

int query(int idx , ll root) {
	if (root > SIZE) {
		return root;
	}
	if (ITree[root * 2] < idx) {
		root += 1;
		printf("root1: %d\n", root);
		query(idx, root * 2);//���������� �̵��� ���� �ڽ����� �̵�
			
	} // ���� ���� �ڽ� ��庸�� idx���� ũ�ٸ� �����ʿ� �����Ѵ�. 
	else {
		printf("root: %d , ITree[root] : %d\n", root , ITree[root]);
		query(idx, root * 2);
	}//�ƴϸ� �׳� ���� �ڽ����� �̵��Ѵ�.  
	return root;
	//printf("ans:%d\n", ITree[root - offset]);
} // ������ ���� ���� �ʿ�� ����. top���� bottom���� ã�ư����Ѵ�. 
int main() {
	scanf("%d", &n); // ���� ���ڿ� ���� �� Ƚ��
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d", &a);
		if (a == 1) { // 1�̸� ������. 
			scanf("%d", &b);
			printf("answer : %d\n", ITree[query(b,1)]);
			update(offset + b, -1);
		}
		else {
			scanf("%d %d", &b, &c); // 2�̸� update�� �Ѵ�.
			update(b, c);
			for (int i = offset; i < 100; i++) {
				printf("ITree2[%d] : %d\n", i, ITree[i]);
			}
		}
	}
	return 0;
}