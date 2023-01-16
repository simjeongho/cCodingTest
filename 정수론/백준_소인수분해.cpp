/*
	�Ҽ� ����Ʈ
	�ݺ��� N = 1�ɶ�����
*/
#pragma warning(disable: 4996)

#include <cstdio>
#define MAX 10000002
using namespace std;
bool isNotPrime[MAX];
int N;
void init() {
	//�����佺�׳׽��� ä 
	for (int i = 2; i * i <= N; i++) {
		for (int j = i * i; j <= N; j += i) {
			isNotPrime[j] = 1;
		}
	}
}
void sol() {
	for (int i = 2; i < MAX; i++) {
		//�Ҽ��� �ƴ϶�� �ǳʶڴ�. 
		if (isNotPrime[i]) continue;
		while (N % i == 0) {
			N /= i;
			printf("%d\n", i);
		}
	}
}
int main() {
	scanf("%d", &N);
	init();
	sol();

}