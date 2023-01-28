#pragma warning (disable:4996)
/*
	Lis�����̴�. 
	dp�迭�� �����ϸ鼭 �κ� ������ ������. 
	1. �ε����� �����ϴ� �迭�� �ϳ� �������ϰ�
	2. ���� ��ų dp�迭�� �ϳ� �־���Ѵ�.
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
		scanf("%d", &original[i]); // �Է��� �޴´�.
		if (v.size() == 0) { 
			v.push_back(original[i]); 
			index[0] = 0;
		} // ���� ���Ͱ� ����ִٸ� Ǫ���Ѵ�.
		//���͸� ��ȸ�ϸ鼭 original[i]���� ���ų� ū ���� ������ �κ��� ã�´�. 
		auto it = lower_bound(v.begin(), v.end(), original[i]);
		if (it == v.end()) {
			//���� original[i]���� ���ų� ū ���� ���� original[i]�� ���� ū �����
			v.push_back(original[i]); // ���Ϳ� �ִ´�. 
			index[v.size() - 1] = i; // �ε��� �迭�� �ִ´�. 
		}
		else {
			//���� ���� �ȿ� ���� ���� original[i]���� ���ų� ū ���� �̹� �����Ѵٸ� �����Ѵ�.
			v[it - v.begin()] = original[i]; // �ε��� �迭�� ���� �ʴ´�. 
		}
	}

	printf("%d\n", v.size());
	return 0;
}