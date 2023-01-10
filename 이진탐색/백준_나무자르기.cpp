#pragma warning(disable:4996)
/*
	trees[i] - ans ���� �������� M�� �Ǿ���� 

	���� ���� �� 2�辿 �÷����� ���? -> ����Ž��?

	���̰� 10���̱⿡ ��Ʈ�� �ȴ�. 
	�߶�ߵǴ� ���̸� ���Ѳ� ���� ���·� �����. 
*/
#include <cstdio>
#include <algorithm>

int N, M;
int trees[1000004];
int ans;
int h = 1;
int binary_search(int start, int end) {
	int mid;
	long long ret;
	int ans = 0;
	while (start <= end) {
		mid = (start + end) / 2;

		ret = 0;
		for (int i = 0; i < N; i++) {
			if (trees[i] > mid) {
				ret += trees[i] - mid;
			}
		}
		if (ret == M) {
			return mid;
		}
		else if (ret > M) {
			if (ans < mid) {
				ans = mid;
			}
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return ans;
}
bool compare(int& a, int& b) {
	if (a < b)return true;
	else return false;
}
int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &trees[i]);
	};

	sort(trees, trees + N, compare);

	printf("%d", binary_search(0, trees[N - 1]));
}