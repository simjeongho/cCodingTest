#pragma warning (disable : 4996)
#include <cstdio>
#define MAX 1002
using namespace std;
int n;
int dp[MAX];

int solution(int num) {
	if (num == 1) return 1;
	if (num == 2) return 3;
	if (dp[num] != 0)return dp[num];
	return dp[num] = (solution(num - 1) + 2*solution(num - 2)) % 10007;
}
int main() {
	scanf("%d", &n);

	printf("%d", solution(n));
	return 0;
}