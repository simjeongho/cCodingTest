#pragma warning (disable:4996)

#include <cstdio>
#include <iostream>
using namespace std;
/*
	��� �м��� ���·� ��Ÿ������ �ִ� ������� ���� �� �����ָ� �ȴ�.
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