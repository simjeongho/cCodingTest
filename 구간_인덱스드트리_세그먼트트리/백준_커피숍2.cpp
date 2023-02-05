#pragma warning (disable : 4996)

#include <cstdio>
#include <algorithm>
#define OFFSET 131072 // 10���� �Ѵ� ������ 2�� ���
#define SIZE_TR 262144 // �ι�
#define ll long long
using namespace std;
int N; // ���� ����
int Q; // ���� ����
ll Tree[SIZE_TR];
int origin[100000 + 2];
int offset = 1;
void initTree() {
	while (offset <= N) offset *= 2; // offset�� ������ش�. 
	for (int i = 0; i < N; i++) Tree[offset + i] = origin[i]; // ���� �迭�� ä���ش�.
	for (int i = offset - 1; i > 0; i--) Tree[i] = Tree[2 * i] + Tree[2 * i + 1]; // Ʈ���� ������ش�. 
}
ll query(int start, int end) {
	if (start > end) swap(start, end);
	ll ans = 0;
	start += offset-1; end += offset-1;
	while (start <= end) {
		if (start % 2) ans += Tree[start++];
		if ((end % 2) == 0) ans += Tree[end--];

		start /= 2; end /= 2;
	}
	return ans;
}
void update(int a, int b) {
	a += offset - 1;
	Tree[a] = b;
	while (a > 0) {
		a /= 2;
		Tree[a] = Tree[a * 2] + Tree[a * 2 + 1];
	}
}
void sol() {
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N; i++) {
		scanf("%d", &origin[i]);
	}
	initTree();
	for (int i = 0; i < Q; i++) {
		int x, y, a, b;
		scanf("%d %d %d %d", &x, &y, &a, &b);
		printf("%lld\n" , query(x, y));
		update(a, b);
	}
}
int main() {

	sol();
	return 0;
}
