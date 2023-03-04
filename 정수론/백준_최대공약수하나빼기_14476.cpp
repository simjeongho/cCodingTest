#pragma warning (disable : 4996)

#include <cstdio>

using namespace std;
int N; // 수의 개수
int nums[1000002];
int LtoR[1000002];
int RtoL[1000002];
int gcd(int a, int b) {
	while (b) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}
void makeGcds() {
	LtoR[0] = nums[0];
	RtoL[N - 1] = nums[N - 1];
	for (int i = 1; i < N; i++) {
		LtoR[i] = gcd(nums[i], LtoR[i - 1]);
		RtoL[N - 1 - i] = gcd(nums[N - 1 - i], RtoL[N - i]);
	}
}

void sol() {
	int ans = RtoL[1]; // 첫번째를 뺏을 때의 경우
	int ansNum = nums[0];

	for (int i = 1; i < N - 1; i++) {
		int temp = gcd(LtoR[i - 1], RtoL[i + 1]);
		if (temp > ans) {
			ans = temp;
			ansNum = nums[i];
		}
	}

	if (LtoR[N - 1] > ans) {
		ans = LtoR[N - 1];
		ansNum = nums[N - 1];
	} // 마지막 수 뺐을 때의 경우

	if ((ansNum % ans) == 0) {
		// 배수라는 뜻이므로
		puts("-1");
	}
	else {
		printf("%d %d",ans, ansNum);
	}
}
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
	}

	makeGcds();

	sol();

	return 0;
}