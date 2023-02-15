#pragma warning (disable : 4996)

#include <cstdio>
#include <algorithm>

#define MAX 1000000
#define SIZE_TR 2097152
#define ll long long
using namespace std;
int N, M, K;
ll origin[MAX + 2];
ll Tree[SIZE_TR];
ll lazy[SIZE_TR];

ll initTree(int node, int start, int end) {
	if (start == end) return Tree[node] = origin[start];
	int mid = (start + end) / 2;
	ll leftResult = initTree(node * 2, start, mid);
	ll rightResult = initTree(node * 2 + 1, mid + 1, end);

	return Tree[node] = leftResult + rightResult;
}
void lazy_update(int node, int start, int end) {
	if (lazy[node] != 0) {
		// lazy node가 존재한다면
		Tree[node] += (end - start + 1) * lazy[node];

		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		} //만약 리프노드가 아니라면 lazy를 물려준다.

		lazy[node] = 0; // 업데이트를 해주었으므로 다시 0으로 만들어준다.
	}
}

void update(int node, int start, int end, int left, int right, ll diff) {
	lazy_update(node, start, end); //먼저 lazy update를 해준다.

	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		Tree[node] += (end - start + 1) * diff; // 값을 업데이트해준다.완전히 포함되면
		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff; // 자식 노드들에 표시를 해둔다.
		}
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right, diff);
	update(node * 2 + 1, mid + 1, end, left, right, diff);
	Tree[node] = Tree[node * 2] + Tree[node * 2 + 1];
}
ll query(int node, int start, int end, int left, int right) {
	lazy_update(node, start, end);
	if (left > end || right < start) return 0;
	if (left <= start && right >= end) return Tree[node];
	int mid = (start + end) / 2;
	ll leftResult = query(node * 2, start, mid, left, right);
	ll rightResult = query(node * 2 + 1, mid + 1, end, left, right);
	return leftResult + rightResult;
}


int main() {

	scanf("%d %d %d", &N, &M, &K); 
	for (int i = 0; i < N; i++) {
		scanf("%lld", &origin[i]);
	}
	initTree(1, 0, N - 1);

	for (int i = 0; i < M + K; i++) {
		int a, b, c; ll d;
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d %d %lld", &b, &c, &d);
			update(1, 0, N - 1, b - 1, c - 1, d);
		}
		else {
			scanf("%d %d", &b, &c);
			printf("%lld\n", query(1, 0, N - 1, b - 1, c - 1));
		}
	}

	return 0;
}