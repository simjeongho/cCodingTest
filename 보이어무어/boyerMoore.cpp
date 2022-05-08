#include <iostream>
#include <String>
#include <fstream>
#include <sstream>
using namespace std;
int Num = 95; // 특수문자, 공백, 알파벳 대 소문자 포함 
int skip[95]; // skip 배열
void initSkip(string p) // skip 배열을 만드는 함수
{
	int i;
	int M = p.length(); // 패턴의 길이
	for (i = 0; i < Num; i++) {
		skip[i] = M;//먼저 패턴의 길이로 skip 배열 초기화
	}
	for (i = 0; i < M; i++) {
		skip[p[i] - 32] = M - i - 1; // 스페이스 바 == 공백에 해당하는 아스키 코드가 32이이고 공백은 출력가능한 문자열 아스키코드 중 가장 값이 작은 값
	}
}

int MisChar(string p, string t) {
	int M = p.length(); // M은 패턴의 길이
	int N = t.length(); // N은 패턴의 길이 
	int k;
	int i = M - 1; // 뒤에서 부터 시작
	int j = M - 1; // 뒤에서 부터 시작 
	initSkip(p); // 입력받은 패턴에 대해 skip 배열을 만든다. 
	while (i < N) { // 입력받은 텍스트를 모두 탐색할 때까지
		for (i, j = M - 1; j >= 0; i -= 1, j -= 1) { // 텍스트와 패턴을 비교한다.
			while (t[i] != p[j]) {
				k = skip[t[i] - 32]; // char형은 아스키 코드로써 배열에 들어가기 때문에 앞서 초기화해준 skip배열과 같게 하기 위해 32를 빼준다. 
				if (M - j > k) i = i + M - j;
				else i = i + k;
				if (i >= N) return N; // 없으면 그냥 텍스트 길이의 마지막을 리턴한다. 
				j = M - 1;//패턴 인덱스 다시 초기화 
			}

		}
		cout << "found at " << i + 1 << "\n"; // 시작 위치를 반환
		i = i + M+ 1; //텍스트의 인덱스를 패턴을 찾은 곳 + 패턴 길이 +1로 하여 패턴이 다음 번부터 비교하기 시작한다. 
	}
		
}

int main() {
	string pattern;
	cout << "검색할 문자열을 입력하세요" << "\n";
	getline(cin, pattern); // 빈칸 포함 string 입력 받기 
	ifstream file("RFC2616_modified.txt"); // 파일을 읽는다.
	istreambuf_iterator<char> begin(file), end; // 파일 전체를 한 번에 읽는다. 
	string text = string(begin, end);// misChar 함수의 파라미터가 string 형이므로 string으로 저장해준다. 
	cout << text;

	MisChar(pattern, text);
	cout << "pattern : " << pattern << "\n";
	for (int i = 0; i < Num; i++) {
		cout << skip[i] << " ";
	}
	cout << "\n";
}