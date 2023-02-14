#pragma warning (disable : 4996)

#include <cstdio>
#include <algorithm>
#define MAX 1000000
#define SIZE_TR 2097152
#define INF 2e9
using namespace std;
int N; int M;
int origin[MAX];
int Tree[SIZE_TR];

int initTree(int node, int start, int end) {
	if (start == end) return Tree[node] = origin[start];
	int mid = (start + end) / 2;
	int leftResult = initTree(node * 2, start, mid);
	int rightResult = initTree(node * 2+1, mid + 1, end);
	return Tree[node] = min(leftResult, rightResult);
	
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return INF;
	if (left <= start && right >= end) return Tree[node];
	int mid = (start + end) / 2;
	int leftResult = query(node * 2, start, mid, left, right);
	int rightResult = query(node * 2+1, mid + 1, end, left, right);

	return min(leftResult, rightResult);
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &origin[i]);
	}

	initTree(1, 0, N - 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", query(1, 0, N - 1, a - 1, b - 1));
	}
	
	return 0;
}