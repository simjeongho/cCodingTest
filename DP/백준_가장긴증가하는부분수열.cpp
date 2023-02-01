#pragma warning (disable : 4996)
#define MAX 1002
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int Ns[MAX];
vector<int> v;
void input() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &Ns[i]);
	}
}

void sol() {
	for (int i = 0; i < N; i++) {
		auto cur = lower_bound(v.begin(), v.end(), Ns[i]);
		int idx = cur - v.begin();
		if (idx == v.size()) {
			v.push_back(Ns[i]);
		}
		else v[idx] = Ns[i];
	}
}
int main() {

	input();
	sol();

	printf("%d\n", v.size());
	return 0;
}