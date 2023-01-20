//11505 구간곱 구하기
/*
	인덱스드 트리 + 유클리드 호제법
	인덱스드 프리는 완전이진트리이다. 
*/
#pragma warning (disable : 4996)
#include <cstdio>

const int SIZE = 2097152; // 2^21
const int BASE = 1048576; // 2^20
const int MOD = 1000000007;
long long ITree[SIZE];

int N, M, K; // N배열 사이즈 M : 변경횟수, K:구간곱연산횟수
void update( int b, int c) {
	b += BASE;//위치
	ITree[b] = c;
	while ((b/=2) > 0) {
		ITree[b] = ITree[b * 2] * ITree[b * 2 + 1] % MOD;
	}
};

int calc(int b, int c) {
	b += BASE, c += BASE;
	long long tmp = 1;
	while (b <= c) {
		if (b & 1) { // b가 오른쪽 자식이면
			tmp = tmp* ITree[b++] %MOD;
		}
		b /= 2;
		if (c % 2 == 0) { // c가 왼쪽 자식이면
			tmp = tmp * ITree[c--] % MOD;
		}
		c /= 2;
	}
	return (int)tmp;
}
int main() {
	scanf("%d %d %d", &N, &M, &K);

	//구간 곱을 구할 때에는 항등원이 1이다. 
	for (int i = BASE + 1; i <= BASE + N; i++) {
		scanf("%d", &ITree[i]);
	}
	for (int i = BASE + N + 1; i < SIZE; i++) {
		ITree[i] = 1; // 곱셈에 대한 항등원은 1이므로 1로 초기화를 해준다. 
	}
	for (int i = BASE - 1; i > 0; i--) {
		ITree[i] = ITree[i * 2] * ITree[i * 2 + 1] % MOD;
	}//인덱스드 트리 Init

	int S = M + K;

	for (int i = 0; i < S; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) { // b번지에 있는 값을 c로 변경
			update(b, c);
		}
		else { // b번지부터 c번지까지의 구간 곱 출력
			printf("%d\n", (int)calc(b, c));
		}
	}

	return 0;
}
