#include <iostream>
#include <String>
#include <fstream>
#include <sstream>
using namespace std;
int Num = 95; // 특수문자, 공백, 알파벳 대 소문자 포함 
int skip[95]; // skip 배열
void initSkip(string p)
{
	int i;
	int M = p.length();
	for (i = 0; i < Num; i++) {
		skip[i] = M;
	}
	for (i = 0; i < M; i++) {
		skip[p[i] - 32] = M - i - 1;
	}
}

int MisChar(string p, string t) {
	int M = p.length();
	int N = t.length();
	int k;
	int i = M - 1;
	int j = M - 1;
	initSkip(p);
	while (i < N) {
		for (i, j = M - 1; j >= 0; i -= 1, j -= 1) {
			while (t[i] != p[j]) {
				k = skip[t[i] - 32];
				if (M - j > k) i = i + M - j;
				else i = i + k;
				if (i >= N) return N;
				j = M - 1;
			}

		}
		cout << "found at " << i + 1 << "\n"; // 시작 위치를 반환
		i = i + M+ 1;
	}
		
}

int main() {
	
	ifstream file("RFC2616_modified.txt");
	istreambuf_iterator<char> begin(file), end;
	string text = string(begin, end);
	cout << text;
	initSkip("part");

	for (int i = 0; i < Num; i++) {
		cout <<  skip[i] << " ";
	}
	cout << "\n";

	MisChar("-- HTTP/", text);
}