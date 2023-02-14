#pragma warning (disable : 4996)

#include <cstdio>
#include <vector>
#define ll long long 
using namespace std;
ll origin[1000001];
ll segTree[2097152];
int N, M, K;

ll makeSegTree(int Node, int start, int end) {
	if (start == end) {
		 return segTree[Node] = origin[start];
	}
	int mid = (start + end) / 2;
	ll leftResult = makeSegTree(Node * 2, start, mid);
	ll rightResult = makeSegTree(Node * 2 + 1, mid + 1, end);
	segTree[Node] = leftResult + rightResult;

	return segTree[Node];
}

//1. 우리가 탐색하는 범위가 우리가 찾고자 하는 구간과 완전히 겹쳐지지 않는 경우
//2. 우리가 탐색하는 범위가, 윌가 찾고자 하는 구간에 완전히 속해있는 경우
//3. 1,2번 경우를 제외한 나머지 경우, 즉 일부만 걸쳐있는 경우

ll query(int node, int start, int end, int left, int right) {
	//left right : 구하고자 하는 범위 
	//start end : 노드가 포함하고 있는 범위 
	if (left > end || right < start) return 0; // 완전히 겹치지 않는 경우
	if (left <= start && right >= end) return segTree[node]; // 노드가 표현하는 구간값이 구하고자 하는 범위에 그대로 들어갈 경우
	int mid = (start + end) / 2;
	ll leftResult = query(node * 2, start, mid, left, right);
	ll rightResult = query(node * 2 + 1, mid + 1, end, left, right);
	return leftResult + rightResult;
}
//1. 바꾸고자 하는 index값이 현재 우리가 탐색하는 범위내에 속해있는 경우
//2. 바꾸고자 하는 index값이 현재 우리가 탐색하는 범위내에 속해있지 않은 경우
//2번의 경우는 더 이상 탐색을 안해도된다. 

void update(int node, int start, int end, int idx, ll diff) {
	if (idx < start || idx > end) return; //완전히 겹치지 않는 경우 리턴
	segTree[node] = segTree[node] + diff;
	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, idx, diff);
		update(node * 2 + 1, mid + 1, end, idx, diff);
	}
}
int main() {

	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &origin[i]);
	}
	makeSegTree(1, 0, N - 1);
	for (int j = 0; j < M + K; j++) {
		int a, b;
		ll c;
		scanf("%d %d %lld", &a, &b, &c);
		if (a == 1) {
			ll diff = c - origin[b-1]; // 원래의 차이
			origin[b - 1] = c; // 바꾼다.
			update(1, 0,N-1, b-1, diff);
		}
		else {
			printf("%lld\n" , query(1, 0, N - 1, b - 1, c - 1));
		}
	}
	return 0;
}