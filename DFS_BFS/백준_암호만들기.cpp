/*
	- ���� �ٸ� L���� ���ĺ� �ҹ��ڵ�� ���� 
	- �ּ� �� ���� ������ �ּ� �� ���� ���� 
	- ���ĵǾ� �־���� 
	- ��ü ������ C������ �����Ѵ�. 
	-C ���� ���ڵ��� ��� �־����� �� ���ɼ� �ִ� ��ȣ���� ��� ���ϴ� ���α׷��� �ۼ��ض�

	- dfs���� (id, moeum, cnt , str)

	1. ���ĺ��� �����ϰų�
		- �����̳� 
		- �����̳�
	2. �������� �ʰų� 

	*/
#if 1
#pragma warning(disable:4996)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int L, C;
int ans;						// ans : ����
#define MAX (15+2)
char inputString[MAX];

vector<string> answerList;

bool charCompare(const char& a, const char& b) {
	if (a < b) return true;
	return false;
}

void input();
void dfs(int id, int moeum, int cnt, string str);
void output();
int main() {
	// 1. �Է¹޴´�
	//freopen("input.txt", "r", stdin);
	input();

	// 2. �����Ѵ�.
	sort(inputString, inputString + C, charCompare);

	// 3. dfs�� �����Ѵ�
	dfs(0, 0, 0, string(""));

	// 4. ������ ����Ѵ�.
	output();

	return 0;
}

void input() {
	scanf("%d %d", &L, &C);
	// cin >> L>> C;
	for (int i = 0; i < C; i++) {
		scanf(" %c", &inputString[i]);
	}
}

// id : ���� ��ġ, moeum : ���� ����, cnt : ���� �迭 ����
void dfs(int id, int moeum, int cnt, string str) {
	// ���ڼ� �� ä�� / �������� 1�� �̻� / ���� 2�� �̻�
	if (cnt == L && moeum >= 1 && cnt - moeum >= 2) {
		answerList.push_back(str);
		return;
	}

	// �迭�� �� ä���� ���ϰ� ����
	if (id == C) return;

	// ������ ���
	if (inputString[id] == 'a' || inputString[id] == 'e'
		|| inputString[id] == 'i' || inputString[id] == 'o'
		|| inputString[id] == 'u') {

		dfs(id + 1, moeum + 1, cnt + 1, str + inputString[id]);
	}

	// ������ ���
	else {
		dfs(id + 1, moeum, cnt + 1, str + inputString[id]);
	}
	// ���ڸ� ���� �� �� ���
	dfs(id + 1, moeum, cnt, str);
}

void output() {
	for (int i = 0; i < answerList.size(); i++) {
		printf("%s\n", answerList[i].c_str());
	}
}
#endif