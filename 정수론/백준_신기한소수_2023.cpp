#pragma warning (disable : 4996)

#include <cstdio>
#include <string>
#define MAX 10000000
using namespace std;

bool isNotPrime[MAX + 1];
int N;
bool checked(int num) {
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
void sol(int cmp, int len) {
	if (len == N) {
		if (checked(cmp)) {
			printf("%d\n", cmp);
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (checked(cmp)) {
			sol(cmp * 10 + i, len + 1);
		}
		else {
			return;
		}
	}
	return;
}
int main() {
	scanf("%d", &N);
	sol(2, 1);
	sol(3, 1);
	sol(5, 1);
	sol(7, 1);
	
	return 0;
}