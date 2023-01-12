#pragma warning (disable:4996)

#include <cstdio>
#include <iostream>
using namespace std;
/*
	기약 분수의 형태로 나타내려면 최대 공약수를 구한 뒤 나눠주면 된다.
*/
int a, A, b, B;

void input() {
	scanf("%d %d %d %d", &a, &A, &b, &B);
}

int gcd(int a, int b) {
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main() {
	input();
	int child = a * B + b * A;
	int parent = A * B;
	int GCD = gcd(parent, child);
	
	cout << child / GCD << " " << parent / GCD << "\n";
}