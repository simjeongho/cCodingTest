#pragma warning (disable:4996)

#include <cstdio>
#include <iostream>

using namespace std;
#define MAX 1002
int N, K;
long long tree[MAX][MAX];
int makeTree() {
	tree[0][0] = tree[1][0] = tree[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= i + 1; j++) {
			if (j == 0 || j == i) {
				tree[i][j] = 1;
			}
			else {
				tree[i][j] = (tree[i - 1][j - 1] + tree[i - 1][j]) % 10007;
			}
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	scanf("%d %d", &N, &K);
	makeTree();
	/*for (int i = 0; i < 30; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << tree[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << tree[N][K] % 10007 << "\n";
	return 0;
}