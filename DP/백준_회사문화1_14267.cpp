#pragma warning (disable : 4996)

#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;
struct pr {
	int id;
	int weight;
	inline bool const operator < (const pr& ref) const {
		return this->id < ref.id;
	}
};
struct bs {
	int id;
	int boss;
	int dp;
	inline bool const operator < (const bs& ref) const {
		return this->boss < ref.boss;
	}
};
int n, m;
bs boss[MAX];
pr praise[MAX];
void input() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		boss[i].id = i;
		scanf("%d", &boss[i].boss);
	}

	for (int i = 1; i <= m; i++) {
		int id, w;
		scanf("%d %d", &id, &w);
		praise[i].id = id;
		praise[i].weight = w;
	}
}

void sol() {
	sort(praise + 1, praise + m + 1);
	for (int i = 1; i <= m; i++) {
		boss[praise[i].id].dp += praise[i].weight;
	}
	for (int i = 2; i <= n; i++) {
		boss[i].dp += boss[boss[i].boss].dp;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", boss[i].dp);
	}
}
int main() {
	input();

	sol();

	return 0;
}