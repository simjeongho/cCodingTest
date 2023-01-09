#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdio>
using namespace std;

unordered_map<int, int> umap;
int N, M;

int temp;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		umap[temp - '0']++;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &temp);
		if (umap[temp - '0']) cout << 1 << "\n";
		else cout << 0 << "\n";
	}

	return 0;
}