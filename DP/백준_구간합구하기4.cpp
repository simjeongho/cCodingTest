#pragma warning (disable : 4996)
#include <cstdio>
#define MAX 100002
int N, M;
/*
	���׸�Ʈ Ʈ���� ������ �迭�� ����
*/
int nums[MAX];
int adds[MAX];
int sol(int start, int end) {
	return adds[end] - adds[start-1];
}
void input() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &nums[i]);
		adds[i] = adds[i-1] + nums[i];
	}
	for (int j = 0; j < M; j++) {
		int a, b = 0;
		scanf("%d %d", &a, &b);

		printf("%d\n", sol(a, b));
	}
}
int main() {
	input();
	return 0;
}