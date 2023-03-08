#pragma warning (disable : 4996)

#include <cstdio>
#include <map>
#define ll long long
#define MAX 1000000
using namespace std;
int N, M; // N개의 수 M으로 나누었을 때 떨어지는 구간의 개수
int nums[MAX + 2];
int sums[MAX + 2];
ll counts[MAX + 2];
map<int, int> mp;
void makeSums() {
	scanf("%d %d", &N, &M);
	mp[0]++;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &nums[i]);
		sums[i] = (sums[i - 1] + (nums[i] % M)) % M;
		counts[i] = counts[i - 1] + i; // 개수
		mp[sums[i]]++;
	}
}
int main() {
	ll ans = 0;
	makeSums();

	/*for (int i = 0; i <= N; i++) {
		printf("%d ", sums[i]);
	}
	printf("\n");

	for (int i = 0; i <= N; i++) {
		printf("%d ", counts[i]);
	}
	printf("\n");*/

	for (auto a : mp) {
		//printf("%d %d\n", a.first, a.second);
		ans += counts[a.second - 1];
	}

	printf("%lld\n", ans);


	return 0;
}