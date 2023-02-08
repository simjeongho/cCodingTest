#pragma warning (disable :4996)

#include <cstdio>
#include <queue>
using namespace std;
bool cmp(int a, int b) {
	if (a > b) return true;
	else return false;
}
priority_queue<int> pq;
int N;
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		if (a != 0) {
			pq.push(a);
		}
		else {
			if (pq.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
	}
	return 0;
}