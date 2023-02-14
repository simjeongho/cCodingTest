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

//1. �츮�� Ž���ϴ� ������ �츮�� ã���� �ϴ� ������ ������ �������� �ʴ� ���
//2. �츮�� Ž���ϴ� ������, ���� ã���� �ϴ� ������ ������ �����ִ� ���
//3. 1,2�� ��츦 ������ ������ ���, �� �Ϻθ� �����ִ� ���

ll query(int node, int start, int end, int left, int right) {
	//left right : ���ϰ��� �ϴ� ���� 
	//start end : ��尡 �����ϰ� �ִ� ���� 
	if (left > end || right < start) return 0; // ������ ��ġ�� �ʴ� ���
	if (left <= start && right >= end) return segTree[node]; // ��尡 ǥ���ϴ� �������� ���ϰ��� �ϴ� ������ �״�� �� ���
	int mid = (start + end) / 2;
	ll leftResult = query(node * 2, start, mid, left, right);
	ll rightResult = query(node * 2 + 1, mid + 1, end, left, right);
	return leftResult + rightResult;
}
//1. �ٲٰ��� �ϴ� index���� ���� �츮�� Ž���ϴ� �������� �����ִ� ���
//2. �ٲٰ��� �ϴ� index���� ���� �츮�� Ž���ϴ� �������� �������� ���� ���
//2���� ���� �� �̻� Ž���� ���ص��ȴ�. 

void update(int node, int start, int end, int idx, ll diff) {
	if (idx < start || idx > end) return; //������ ��ġ�� �ʴ� ��� ����
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
			ll diff = c - origin[b-1]; // ������ ����
			origin[b - 1] = c; // �ٲ۴�.
			update(1, 0,N-1, b-1, diff);
		}
		else {
			printf("%lld\n" , query(1, 0, N - 1, b - 1, c - 1));
		}
	}
	return 0;
}