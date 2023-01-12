#pragma warning(disable : 4996)
/*
	�������� ���ϴµ� 
	���԰� ������
	����ϰ� �Ͼ�ٶ�..
	�ε����� Ʈ�� or ���׸�Ʈ Ʈ��?

	Ǯ��
	-> ������ �Ͼ�� Ƚ���� ������ ���� ���ϴ� ������ ��û ŭ
	long long : 2^63

	���׸�Ʈ Ʈ���� �ε�����Ʈ�� �� �� ���� 
	nn =  N�� �Է� / N���� ū 2^������ ( offset)
	�迭�� ������ 2�踦 �Ѵ� ������ 2�� ������

	void init() {
		while(offset < N) offset*=2;
		for(int i=0; i < N; i++) tree[offset+i] = nos[i];
		for(int i=N; i < offset; i++) tree[offset+i] = 0;
		for(int i = offset-1; i>0; i--) tree[i] = tree[i*2] + tree[i*2+1];
	}

	void update(int idx, ll val) {
		idx += offset;
		tree[idx] = val;
		while(idx > 0){
		
		}
	}
*/
//M�� ���� ������ �Ͼ�� Ƚ��
//K�� ������ ���� ���ϴ� Ƚ��

// �����
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;
ll arr[1000001];
ll tree[1000001];
/*
    N�� ���� ����
    M�� ���� ������ �Ͼ�� Ƚ��
    K�� ������ ���� ���ϴ� Ƚ��

    a�� 1�� ���� ��ȯ
    a�� 2�� ���� ������ ���ϱ�
*/
int N, M, K;
void update(int idx, ll val) {
    while (idx <= N) {
        tree[idx] += val;
        cout << "idx:" << idx << " -idx:" << -idx << "\n";
        idx += (idx & -idx);
    }
}
ll query(int idx) {
    ll sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int main() {
    //N,M,K�� �Է¹޴´�.
    scanf("%d%d%d", &N, &M, &K);
    //�Է°� ���ÿ� �ε����� Ʈ���� �����Ѵ�.
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &arr[i]);
        update(i, arr[i]);
    }
    for (int i = 0; i < 200; i++) {
        cout << tree[i] << " ";
    }
    for (int i = 0; i < M + K; i++) {
        ll a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a == 1) {
            update(b, -arr[b]);
            update(b, c);
            arr[b] = c;
        }
        else
            printf("%lld\n", query(c) - query(b - 1));
    }

    for (int i = 0; i < 200; i++) {
        cout << tree[i] << " ";
    }
    return 0;
}