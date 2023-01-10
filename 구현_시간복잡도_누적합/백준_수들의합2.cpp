#pragma warning(disable:4996)
/*
	누적합 문제인 거 같다. 
	누적합 배열을 만들어준 후
	for 문을 돌면서 빼줘야 할 듯 하다.  
*/
#include <iostream>
#include <algorithm>
#include <cstdio>

#define MAX 10004
using namespace std;

int N;
int M;
int nums[MAX];
int adds[MAX];
int ans;
int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &nums[i]);
		adds[i] = adds[i - 1] + nums[i];
	}

	for (int i = 0; i <= N; i++) {
		for (int j = i+1; j <= N; j++) {
			if (adds[j] - adds[i] == M) {
				ans++;
				break;
			}
			// 누적 합의 차가 M보다 커질 경우에는 break한다.
			if (adds[j] - adds[i] > M) {
				break;
			}
		}
	}

	cout << ans << "\n";
}