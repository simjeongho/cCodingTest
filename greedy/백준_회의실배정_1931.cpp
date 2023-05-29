#pragma warning (disable : 4996)

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N;
struct node {
	int start;
	int end;

	bool const operator < (node& ref) const {
		return this->end < ref.end;
	}
};
int ans = 1;
vector<node> v;
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		v.push_back({ s, e });
	}

	sort(v.begin(), v.end());
	int endTime = v[0].end;
	for (int i = 1; i < N; i++) {
		if (v[i].start >= endTime) {
			endTime = v[i].end;
			ans++;
		}
	}

	printf("%d\n", ans);
	return 0;
}