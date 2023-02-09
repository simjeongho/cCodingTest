#pragma warning (disable : 4996)
#include <cstdio>
#include <unordered_map>
#include <algorithm>
#define MAX 524288
#define SIZE_TR 1048576
#define ll long long
using namespace std;
struct BB {
	int idxA;
	int idxB;
	bool inline const operator < (const BB& ref) const {
		if (this->idxA > ref.idxA) return true;
		else return false;
	}
};
unordered_map<int, int> mp;
int N;
int originA[500002]; //int 배열 
BB originB[500002];
ll Tree[SIZE_TR];
int offset = 1;
ll final;
void input() {
	//입력을 받아들인다. 
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &originA[i]);
		mp[originA[i]] = i; //인덱스를 저장 
	}
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		originB[i].idxA = mp[tmp]; // A인덱스를 저장한다. 
		originB[i].idxB = i; // B인덱스를 저장한다.
	}
}
int query(int from, int to) {
	int ans = 0;
	from += offset; to += offset;
	while (from <= to) {
		if (from % 2) ans += Tree[from++];
		if ((to % 2) == 0) ans += Tree[to--];
		from /= 2; to /= 2;
	}
	return ans-1;
}
void update(int idx) {
	idx += offset;
	Tree[idx] = 1;
	idx /= 2;
	while (idx > 0) {
		Tree[idx] = Tree[idx * 2] + Tree[idx * 2 + 1];
		idx /= 2;
	}
	/*for (int i = 0; i <= 15; i++) {
		printf("%d ", Tree[i]);
	}
	printf("\n");*/
}
void sol() {
	for (int i = 0; i < N; i++) {
		update(originB[i].idxB);
		final += query(0, originB[i].idxB);
	}
}
int main() {
	input();
	sort(originB, originB + N); // 오름차순으로 정렬 
	while (offset < N) offset *= 2; // offset을 만든다. 
	sol();
	printf("%lld\n", final);
	return 0;
}