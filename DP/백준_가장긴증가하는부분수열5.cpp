#pragma warning (disable: 4996)

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#define BUFFMAX 13000000

int N;
int A[1000001], PA[1000001]; // A:���� ���� PA:LIS���� ���� �� �ٷ� �տ� �;� �ϴ� ���� �ε��� ��ȣ 
int D[1000001];
int Dsize, ID[1000001]; // D:LISĳ��, ID:�ش� ĳ�ð��� ���������� �ε��� ��ȣ
int Answer[1000001]; // LIS���� �����ϴ� buffer
using namespace std;
int main() {
	static char buff[BUFFMAX];
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	scanf("%d ", &N);
	fgets(buff, BUFFMAX, stdin);
	char* c = buff;
	for (int i = 1; i <= N; i++) {
		A[i] = atoi(strtok(c, " \n\t")); // atoi : ǥ�ض��̺귯�� �Լ� itoa : ��ǥ��
		c = nullptr;
	}

	for (int i = 1; i <= N; i++) {
		int* tmp = std::lower_bound(D, D + Dsize, A[i]); // lower_bound
		int index = tmp - D; // ������ ���� ������-������ offset�� ���´�. �迭�� �������� ���´�. 
		D[index] = A[i]; // *tmp = A[i];
		ID[index] = i;
		if (index >= 1) PA[i] = ID[index - 1];
		else PA[i] = -1;
		if (index == Dsize) Dsize++;
	}

	//reverse tracking �Ųٷ� ã�ư���. 
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