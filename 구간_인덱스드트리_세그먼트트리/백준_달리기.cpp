#pragma warning (disable:4996)

/*
	�� ����
	�ڽ��� �����ؼ� �������� �� �ڽ��� ��ġ?
	���� ���� �̹� ���ĵǾ� �ִٸ�(�޸������̼�) �ڽŸ� ���� �ȴ�. 

	Ǯ��
	1) �߿��ϰų� - 1��
	2) �߿� ���ϰų� - 2��
	1) ���� �༮�鸸 ���� �ȴ�. 
	2) ���� �༮ �� �߿� ������ ����� ���� ���ش�. 

	���� ����?
	500000 * 500000 �ð� ���⵵ ���� x
	-> �� �տ� �ִ� �༮��� �� ���ؼ� �޸��� �Ƿ� ���� �ֵ� ī��Ʈ 

	ù ��° ���
	1. mergeSort merge Sort�� ������ �� ������ ���ϴ� ��Ȳ�� �߿��̶�� �����Ѵ�. 
	
	2. ���� �� ���� 
	O(N^2) -> O(logN)���� ����� �� �ڷᱸ���� �ʿ��ϴ�. 
	! segmentTree
	�ڽ��� ������� �� ���� ���� �ø���. 
	�ڽ��� �ִ� �� �� 

	segmet Tree�� ������ ������ ����..?

	�ε����� Ʈ�� 
	�ε����� �� Ʈ�� 
	���� ���� ���� ���´�. 

	-- 2^n��ŭ�� ������ �ʿ��ϴ�. 
	-- 2^nn >= N*2�� ������ �� 
*/
#include <cstdio>
#include <algorithm>
#define OFFSET 524288
#define SIZE_TR 1048576
using namespace std;
int N; // ���� ��
int Tree[SIZE_TR];
int ans[500004];
struct player {
	int idx;
	int speed;
}; // ������ �ε����� speed�� ������ ����ü
player origin[500004]; // ���� �迭
bool compare (player a, player b) {
	if (a.speed > b.speed) return true;
	else return false;
}
void input() {
	scanf("%d" , &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &origin[i].speed);
		origin[i].idx = i;
	}
}
void update(int idx) {
	idx += OFFSET;
	Tree[idx] = 1; // 1�� �����ش�. 
	while (idx > 0) {
		idx /= 2;
		Tree[idx] = Tree[idx * 2] + Tree[idx * 2 + 1]; // ������ ���鼭 ������Ʈ
	}
}
int query(int start, int end) {
	int ans = 0;
	start += OFFSET, end += OFFSET; //�������� ���� ��� OFFSET�� �����ش�.
	while (start <= end) {
		if (start % 2) ans += Tree[start++];
		if (end % 2 == 0) ans += Tree[end--];
		start /= 2; end /= 2;
	}
	return ans;
}
void sol() {
	sort(origin, origin + N, compare);
	for (int i = 0; i < N; i++) {
		//printf("origin[%d].idx : %d\n", i, origin[i].idx);
		update(origin[i].idx);
		ans[origin[i].idx] = query(0, origin[i].idx);
		//printf("%d\n", query(0, origin[i].idx));
	}

	for (int i = 0; i < N; i++) {
		printf("%d\n", ans[i]);
	}
}
int main() {
	input();
	sol();
	return 0;
}