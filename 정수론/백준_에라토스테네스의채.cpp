#pragma warning (disable:4996)

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
/*
	2���� N������ ��� ������ ���´�.
	���� ������ ���� �� �� ���� ���� ���� ã�´�. �̰��� p��� �ϰ� �� ���� �Ҽ��̴�.
	p�� �����, ���� ������ ���� p�� ����� ũ�� ������� �����. 
	���� ��� ���� ������ �ʾҴٸ� �ٽ� 2�� �ܰ�� ����.
*/
using namespace std;

#define MAX 1000 + 3

int N, K;
bool isNotPrimenumber[MAX];

int main() {
	scanf("%d %d", &N, &K);

	// 2. �����佺�׳׽��� ü
	int cnt = 0;	// ���� Ƚ�� ī��Ʈ
	for (int i = 2; i <= N; i++) {

		// 1) �̹� ���������� pass
		if (isNotPrimenumber[i] == true) {
			continue;
		}

		// 2) ��� ����
		for (int j = i; j <= N; j += i) {
			if (isNotPrimenumber[j] == false) {

				isNotPrimenumber[j] = true;
				cnt++;

				// K��° ����� ���� ���
				if (cnt == K) {
					printf("%d", j);
					return 0;
				}

			}
		}

	}

	return 0;

}