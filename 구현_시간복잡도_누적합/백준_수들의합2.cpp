#pragma warning(disable:4996)
/*
	������ ������ �� ����. 
	������ �迭�� ������� ��
	for ���� ���鼭 ����� �� �� �ϴ�.  
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
			// ���� ���� ���� M���� Ŀ�� ��쿡�� break�Ѵ�.
			if (adds[j] - adds[i] > M) {
				break;
			}
		}
	}

	cout << ans << "\n";
}