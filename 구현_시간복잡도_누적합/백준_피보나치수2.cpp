#pragma warning (disable : 4996)

#include <cstdio>
#include <iostream>
int n;
long long adds[94];

using namespace std;

int main() {
	scanf("%d", &n);
	adds[0] = 0;
	adds[1] = 1;
	for (int i = 2; i <= n; i++) {
		adds[i] = adds[i - 1] + adds[i - 2];
	}

	cout << adds[n] << "\n";
}