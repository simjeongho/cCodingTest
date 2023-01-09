/*
	- 서로 다른 L개의 알파벳 소문자들로 구성 
	- 최소 한 개의 모음과 최소 두 개의 자음 
	- 정렬되어 있어야함 
	- 전체 종류를 C가지로 가정한다. 
	-C 개의 문자들이 모두 주어졌을 때 가능성 있는 암호들을 모두 구하는 프로그램을 작성해라

	- dfs수행 (id, moeum, cnt , str)

	1. 알파벳을 선택하거나
		- 모음이냐 
		- 자음이냐
	2. 선택하지 않거나 

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
int ans;						// ans : 정답
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
	// 1. 입력받는다
	//freopen("input.txt", "r", stdin);
	input();

	// 2. 정렬한다.
	sort(inputString, inputString + C, charCompare);

	// 3. dfs를 수행한다
	dfs(0, 0, 0, string(""));

	// 4. 정답을 출력한다.
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

// id : 현재 위치, moeum : 모음 개수, cnt : 만들 배열 길이
void dfs(int id, int moeum, int cnt, string str) {
	// 글자수 다 채움 / 모음개수 1개 이상 / 자음 2개 이상
	if (cnt == L && moeum >= 1 && cnt - moeum >= 2) {
		answerList.push_back(str);
		return;
	}

	// 배열을 다 채우지 못하고 종료
	if (id == C) return;

	// 모음인 경우
	if (inputString[id] == 'a' || inputString[id] == 'e'
		|| inputString[id] == 'i' || inputString[id] == 'o'
		|| inputString[id] == 'u') {

		dfs(id + 1, moeum + 1, cnt + 1, str + inputString[id]);
	}

	// 자음인 경우
	else {
		dfs(id + 1, moeum, cnt + 1, str + inputString[id]);
	}
	// 문자를 선택 안 할 경우
	dfs(id + 1, moeum, cnt, str);
}

void output() {
	for (int i = 0; i < answerList.size(); i++) {
		printf("%s\n", answerList[i].c_str());
	}
}
#endif