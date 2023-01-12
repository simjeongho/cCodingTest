#pragma warning(disable : 4996)
/*
	구간합을 구하는데 
	삽입과 삭제가
	빈번하게 일어난다라..
	인덱스드 트리 or 세그먼트 트리?

	풀이
	-> 변경이 일어나는 횟수와 구간의 합을 구하는 개수도 엄청 큼
	long long : 2^63

	세그먼트 트리와 인덱스드트리 둘 다 가능 
	nn =  N개 입력 / N보다 큰 2^제곱수 ( offset)
	배열의 사이즈 2배를 넘는 최초의 2의 제곱수

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
//M은 수의 변경이 일어나는 횟수
//K는 구간의 합을 구하는 횟수

// 비재귀
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;
ll arr[1000001];
ll tree[1000001];
/*
    N은 수의 개수
    M은 수의 변경이 일어나는 횟수
    K는 구간의 합을 구하는 횟수

    a가 1인 경우는 교환
    a가 2인 경우는 구간합 구하기
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
    //N,M,K를 입력받는다.
    scanf("%d%d%d", &N, &M, &K);
    //입력과 동시에 인덱스드 트리를 구성한다.
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