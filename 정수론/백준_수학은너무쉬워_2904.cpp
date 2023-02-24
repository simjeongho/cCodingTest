#pragma warning (disable : 4996)

#include <cstdio>
#include <map>
#include <vector>
#define ll long long
using namespace std;
map<ll, ll> mp;
int cnt1;
int N;
map<int, int> mps[101];
void makeMap(int num, int cnt) {
	for (int i = 2; i* i <= num; i++) {
		while (num % i == 0) {
			mp[i]++;
			mps[cnt][i]++;
			num /= i;
		}
	}
	if (num != 1) {
		++mp[num];
		++mps[cnt][num];
	}
}
ll GCD = 1;
vector<pair<int, int>> gcds;
void sol() {
	for (auto a : mp) {
		if (a.second >= N) {
			GCD *= a.first;
			GCD *= (a.second / N);
			gcds.push_back({ a.first, (a.second / N) });
		}
	}
	for (int i = 0; i < N; i++) {
		for (auto a : gcds) {
			if (mps[i][a.first] < a.second) {
				//printf("mp[%d][%d] : %d a.second : %d\n", i, a.first, mps[i][a.first], a.second);
				cnt1 += a.second - mps[i][a.first];
			}
		}
	}

}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		makeMap(temp, i);
	}
	sol();
	printf("%lld %d\n", GCD, cnt1);
	/*for (int i = 0; i < N; i++) {
		for (auto a : mps[i]) {
			printf("i : %d %d %d\n",i, a.first, a.second);
		}
		printf("\n");
	}*/
	return 0;
}