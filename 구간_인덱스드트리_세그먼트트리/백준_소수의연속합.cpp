#pragma warning(disable:4996)
/*
	소수의 합으로 나타낼 수 있는 자연수들이 있다. 
	하지만 그렇지 못한 것도 있다. 
	소수들의 합
	인덱스드 트리?
	슬라이딩 윈도우 이용 

*/
#include <iostream>
#include <cstdio>
#define MAX (4000000+3)
#define ll long long
using namespace std;
int N;
bool isNotPrime[MAX];
int tree[4 * MAX];
int offset = 1;
int cnt;
void init() {
	//에라토스테네스의 채
	for (int i = 2; i*i < MAX; i++) {
		if (isNotPrime[i] == false) {
			for (int j = i*i; j < MAX; j += i) {
				isNotPrime[j] = true;
			}
		}
	}
}

void makeTree() {
	while (offset < N) offset *= 2;
	int idx = 0;
	for (int i = 2; i <= N; i++) {
		if (isNotPrime[i] == false) {
			tree[offset + idx] = i;
			idx++;
			cnt++;
		}
	}
	for (int j = offset-1; j > 0; j--) {
		tree[j] = tree[2 * j] + tree[2 * j + 1];
	}
}
int query1(int from, int to) {
	ll res = 0;
	from += offset; to += offset;
	while (from <= to) {
		if (from % 2 == 1) res += tree[from++];
		if (to % 2 == 0) res += tree[to--];

		from /= 2; to /= 2;
	}
	return res;
}
int ans;
void sol() {
	int from = 0; int to = 0;
	while (from < cnt) {
		int tmp = query1(from, to);
		if (to >= cnt && tmp <= N) break;
		if ( tmp == N) {
			ans++;
			to++;
		}
		else if (tmp < N) {
			to++;
		}
		else if (tmp > N) {
			from++;
		}
	}
	printf("%d", ans);
}
int main() {

	scanf("%d", &N);
	init();
	/*for (int i = 2; i < N; i++) {
		printf("%d ", isNotPrime[i]);
	}*/
	makeTree();
	sol();
	return 0;
}
