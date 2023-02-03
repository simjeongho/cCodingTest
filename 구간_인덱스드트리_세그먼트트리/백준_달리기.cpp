#pragma warning (disable:4996)

/*
	내 생각
	자신을 포함해서 정렬했을 때 자신의 위치?
	만약 앞이 이미 정렬되어 있다면(메모이제이션) 자신만 들어가면 된다. 

	풀이
	1) 추월하거나 - 1등
	2) 추월 못하거나 - 2등
	1) 앞의 녀석들만 보면 된다. 
	2) 앞의 녀석 중 추월 가능한 놈들의 수를 빼준다. 

	이중 포문?
	500000 * 500000 시간 복잡도 성립 x
	-> 내 앞에 있는 녀석들과 쭉 비교해서 달리기 실력 낮은 애들 카운트 

	첫 번째 방법
	1. mergeSort merge Sort를 진행할 때 순서가 변하는 상황을 추월이라고 생각한다. 
	
	2. 구간 합 문제 
	O(N^2) -> O(logN)으로 만들어 줄 자료구조가 필요하다. 
	! segmentTree
	자신의 리프노드 두 개의 합을 올린다. 
	자식은 최대 두 개 

	segmet Tree의 장점은 구현이 쉽다..?

	인덱스드 트리 
	인덱싱을 한 트리 
	구간 합을 구해 놓는다. 

	-- 2^n만큼의 공간이 필요하다. 
	-- 2^nn >= N*2인 최초의 수 
*/
#include <cstdio>
#include <algorithm>
#define OFFSET 524288
#define SIZE_TR 1048576
using namespace std;
int N; // 선수 수
int Tree[SIZE_TR];
int ans[500004];
struct player {
	int idx;
	int speed;
}; // 원래의 인덱스와 speed를 저장할 구조체
player origin[500004]; // 원본 배열
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
	Tree[idx] = 1; // 1을 더해준다. 
	while (idx > 0) {
		idx /= 2;
		Tree[idx] = Tree[idx * 2] + Tree[idx * 2 + 1]; // 끝까지 가면서 업데이트
	}
}
int query(int start, int end) {
	int ans = 0;
	start += OFFSET, end += OFFSET; //시작점과 끝점 모두 OFFSET을 더해준다.
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