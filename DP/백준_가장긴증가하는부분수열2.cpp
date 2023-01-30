#pragma warning (disable:4996)
/*
	Lis문제이다. 
	dp배열을 갱신하면서 부분 수열을 만들어간다. 
	1. 인덱스를 저장하는 배열을 하나 만들어야하고
	2. 갱신 시킬 dp배열이 하나 있어야한다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 1000000 + 4
using namespace std;

int original[MAX];
int index[MAX];
int N;
vector<int> v;
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &original[i]); // 입력을 받는다.
		if (v.size() == 0) { 
			v.push_back(original[i]); 
			index[0] = 0;
		} // 만약 벡터가 비어있다면 푸쉬한다.
		//벡터를 순회하면서 original[i]보다 같거나 큰 값이 나오는 부분을 찾는다. 
		auto it = lower_bound(v.begin(), v.end(), original[i]);
		if (it == v.end()) {
			//만약 original[i]보다 같거나 큰 수가 없이 original[i]가 가장 큰 수라면
			v.push_back(original[i]); // 벡터에 넣는다. 
			index[v.size() - 1] = i; // 인덱스 배열에 넣는다. 
		}
		else {
			//만약 벡터 안에 새로 들어온 original[i]보다 같거나 큰 수가 이미 존재한다면 변경한다.
			v[it - v.begin()] = original[i]; // 인덱스 배열은 넣지 않는다. 
		}
	}

	printf("%d\n", v.size());
	return 0;
}