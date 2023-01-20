//11505 ������ ���ϱ�
/*
	�ε����� Ʈ�� + ��Ŭ���� ȣ����
	�ε����� ������ ��������Ʈ���̴�. 
*/
#pragma warning (disable : 4996)
#include <cstdio>

const int SIZE = 2097152; // 2^21
const int BASE = 1048576; // 2^20
const int MOD = 1000000007;
long long ITree[SIZE];

int N, M, K; // N�迭 ������ M : ����Ƚ��, K:����������Ƚ��
void update( int b, int c) {
	b += BASE;//��ġ
	ITree[b] = c;
	while ((b/=2) > 0) {
		ITree[b] = ITree[b * 2] * ITree[b * 2 + 1] % MOD;
	}
};

int calc(int b, int c) {
	b += BASE, c += BASE;
	long long tmp = 1;
	while (b <= c) {
		if (b & 1) { // b�� ������ �ڽ��̸�
			tmp = tmp* ITree[b++] %MOD;
		}
		b /= 2;
		if (c % 2 == 0) { // c�� ���� �ڽ��̸�
			tmp = tmp * ITree[c--] % MOD;
		}
		c /= 2;
	}
	return (int)tmp;
}
int main() {
	scanf("%d %d %d", &N, &M, &K);

	//���� ���� ���� ������ �׵���� 1�̴�. 
	for (int i = BASE + 1; i <= BASE + N; i++) {
		scanf("%d", &ITree[i]);
	}
	for (int i = BASE + N + 1; i < SIZE; i++) {
		ITree[i] = 1; // ������ ���� �׵���� 1�̹Ƿ� 1�� �ʱ�ȭ�� ���ش�. 
	}
	for (int i = BASE - 1; i > 0; i--) {
		ITree[i] = ITree[i * 2] * ITree[i * 2 + 1] % MOD;
	}//�ε����� Ʈ�� Init

	int S = M + K;

	for (int i = 0; i < S; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) { // b������ �ִ� ���� c�� ����
			update(b, c);
		}
		else { // b�������� c���������� ���� �� ���
			printf("%d\n", (int)calc(b, c));
		}
	}

	return 0;
}
