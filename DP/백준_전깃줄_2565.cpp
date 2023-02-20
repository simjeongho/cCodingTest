#pragma warning (disable : 4996)

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int N; // 전깃줄의 개수
int cnt; //없애야하는 전깃줄 수
struct line {
	int start;
	int end;
	inline bool const operator < (const line& ref) const {
		return this->start < ref.start;
	}
};
vector<line>lines;
vector<int> ans;
void input() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		lines.push_back({ s,e });
	}
}

void sol() {
	sort(lines.begin(), lines.end());
	for (int i = 0; i < lines.size(); i++) {
		auto idx = lower_bound(ans.begin(), ans.end(), lines[i].end);
		int id = idx - ans.begin();
		//printf("id : %d\n", id);
		if (id >= ans.size()) {
			ans.push_back(lines[i].end);
		}
		else {
			ans[id] = lines[i].end;
		}			
	}
	printf("%d\n", N - ans.size());
}
int main() {
	input();
	sol();

	return 0;
}