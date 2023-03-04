#pragma warning (disable : 4996)
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
int A, B;
int resA;
int resB;
int cmp = A+B;
int makeGcd(int a, int b) {
	if (a < b) swap(a, b);
	while (b) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

void sol() {
	int temp = B / A;
	resA = A;
	resB = B;
	for (int i = 2; i * i < temp; i++) {
		if ((temp % i) == 0) {
			if (makeGcd(temp / i, i) == 1) {
				// 서로소가 1이라면 
				if ((i * A) + ((temp / i) * A) < resA + resB) {
					resA = i * A;
					resB = (temp / i) * A;
				}
			}
		}
	}
	if (resA > resB) swap(resA, resB);
	printf("%d %d\n", resA, resB);
}
int main() {

	scanf("%d %d", &A, &B);
	sol();
	return 0;
}