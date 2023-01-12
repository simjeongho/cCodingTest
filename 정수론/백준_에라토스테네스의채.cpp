#pragma warning (disable:4996)

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
/*
	2부터 N까지의 모든 정수를 적는다.
	아직 지우지 않은 수 중 가장 작은 수를 찾는다. 이것을 p라고 하고 이 수는 소수이다.
	p를 지우고, 아직 지우지 않은 p의 배수를 크기 순서대로 지운다. 
	아직 모든 수를 지우지 않았다면 다시 2번 단계로 간다.
*/
using namespace std;

#define MAX 1000 + 3

int N, K;
bool isNotPrimenumber[MAX];

int main() {
	scanf("%d %d", &N, &K);

	// 2. 에라토스테네스의 체
	int cnt = 0;	// 지운 횟수 카운트
	for (int i = 2; i <= N; i++) {

		// 1) 이미 지워졌으면 pass
		if (isNotPrimenumber[i] == true) {
			continue;
		}

		// 2) 배수 제거
		for (int j = i; j <= N; j += i) {
			if (isNotPrimenumber[j] == false) {

				isNotPrimenumber[j] = true;
				cnt++;

				// K번째 지우는 순간 출력
				if (cnt == K) {
					printf("%d", j);
					return 0;
				}

			}
		}

	}

	return 0;

}