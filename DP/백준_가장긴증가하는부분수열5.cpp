#pragma warning (disable: 4996)

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#define BUFFMAX 13000000

int N;
int A[1000001], PA[1000001]; // A:원래 수열 PA:LIS에서 현재 수 바로 앞에 와야 하는 수의 인덱스 번호 
int D[1000001];
int Dsize, ID[1000001]; // D:LIS캐시, ID:해당 캐시값의 원래수열의 인덱스 번호
int Answer[1000001]; // LIS값을 저장하는 buffer
using namespace std;
int main() {
	static char buff[BUFFMAX];
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	scanf("%d ", &N);
	fgets(buff, BUFFMAX, stdin);
	char* c = buff;
	for (int i = 1; i <= N; i++) {
		A[i] = atoi(strtok(c, " \n\t")); // atoi : 표준라이브러리 함수 itoa : 비표준
		c = nullptr;
	}

	for (int i = 1; i <= N; i++) {
		int* tmp = std::lower_bound(D, D + Dsize, A[i]); // lower_bound
		int index = tmp - D; // 포인터 연산 포인터-포인터 offset이 나온다. 배열의 번지수가 나온다. 
		D[index] = A[i]; // *tmp = A[i];
		ID[index] = i;
		if (index >= 1) PA[i] = ID[index - 1];
		else PA[i] = -1;
		if (index == Dsize) Dsize++;
	}

	//reverse tracking 거꾸로 찾아간다. 
	int aindex = ID[Dsize - 1];
	for (int i = Dsize - 1; i >= 0; i--) {
		Answer[i] = A[aindex];
		aindex = PA[aindex];
	}
	printf("%d\n", Dsize);
	for (int j = 0; j < Dsize; j++) {
		printf("%d ", Answer[j]);
	}
	return 0;
}