/*
	소수 리스트
	반복문 N = 1될때까지
*/
#pragma warning(disable: 4996)

#include <cstdio>
#define MAX 10000002
using namespace std;
bool isNotPrime[MAX];
int N;
void init() {
	//에라토스테네스의 채 
	for (int i = 2; i * i <= N; i++) {
		for (int j = i * i; j <= N; j += i) {
			isNotPrime[j] = 1;
		}
	}
}
void sol() {
	for (int i = 2; i < MAX; i++) {
		//소수가 아니라면 건너뛴다. 
		if (isNotPrime[i]) continue;
		while (N % i == 0) {
			N /= i;
			printf("%d\n", i);
		}
	}
}
int main() {
	scanf("%d", &N);
	init();
	sol();

}