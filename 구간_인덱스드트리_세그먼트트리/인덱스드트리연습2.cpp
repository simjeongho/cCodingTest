#pragma warning (disable: 4996)

#include <cstdio>
#define SIZE 1LL << 20 // 1048576
#define ll long long
using namespace std;
int offset = SIZE;
long long ITree[SIZE << 1];
int n;
void init() {
	
} // 사실 빈 상자로 시작하므로 init함수는 필요없다. 

void update(int idx, int val) {
	idx += offset;
	ITree[idx] += val; // 들어온 사탕을 더해준다.
	while (idx > 0) {
		idx /= 2;
		ITree[idx] = ITree[idx * 2] + ITree[idx * 2 + 1];
		printf("ITree[%d]  = %d + %d\n", idx, ITree[idx * 2] + ITree[idx * 2 + 1]);
	}
} // 업데이트 함수

int query(int idx , ll root) {
	if (root > SIZE) {
		return root;
	}
	if (ITree[root * 2] < idx) {
		root += 1;
		printf("root1: %d\n", root);
		query(idx, root * 2);//오른쪽으로 이동후 왼쪽 자식으로 이동
			
	} // 만약 왼쪽 자식 노드보다 idx값이 크다면 오른쪽에 존재한다. 
	else {
		printf("root: %d , ITree[root] : %d\n", root , ITree[root]);
		query(idx, root * 2);
	}//아니면 그냥 왼쪽 자식으로 이동한다.  
	return root;
	//printf("ans:%d\n", ITree[root - offset]);
} // 구간의 합을 구할 필요는 없다. top에서 bottom으로 찾아가야한다. 
int main() {
	scanf("%d", &n); // 사탕 상자에 손을 댄 횟수
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d", &a);
		if (a == 1) { // 1이면 꺼낸다. 
			scanf("%d", &b);
			printf("answer : %d\n", ITree[query(b,1)]);
			update(offset + b, -1);
		}
		else {
			scanf("%d %d", &b, &c); // 2이면 update를 한다.
			update(b, c);
			for (int i = offset; i < 100; i++) {
				printf("ITree2[%d] : %d\n", i, ITree[i]);
			}
		}
	}
	return 0;
}