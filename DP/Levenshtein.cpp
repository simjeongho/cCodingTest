#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <tchar.h>
using namespace std;
//12171800 심정호
wstring input1, input2;
wstring kosource, kotarget;
double weightDist[1001][1001];
vector <string> path; // path에 해당하는 연산을 저장할 벡터 
void printweightDist(wstring input1, wstring input2) { // weight distance를 출력해주는 함수 
	for (int i = 0; i <= input2.length(); i++) {
		for (int j = 0; j <= input1.length(); j++) {
			cout << weightDist[i][j] << " ";
		}
		cout << "\n";
	}
}
//12171800 심정호
void pathPrint(wstring source, wstring target) {
	int i = target.length();// target 인덱스 + 1에 해당함
	int j = source.length(); // source 의 인덱스 + 1에 해당함 
	while (i >= 0 && j >= 0) // dist배열의 인덱스가 0보다 클 때만 진행한다. 
	{
		if (i != 0 && j != 0) { // 삽입연산 삭제연산 교체연산 세 가지 경우의 수가 모두 존재할 때
			if (source[j - 1] == target[i - 1]) { // 만약 각 인덱스에 해당하는 값이 같다면
				//cout << source[j - 1] << " " << target[i - 1] << "\n";
				cout << i << " " << j << "same\n";
				i -= 1;// 그냥 대각선으로 올라간다. 비용 0
				j -= 1;
			}
			else
			{
				if (min(weightDist[i - 1][j], min(weightDist[i - 1][j - 1], weightDist[i][j - 1])) == weightDist[i - 1][j]) { // 하지만 각 인덱스에 해당하는 값이 다르면서 최소 값이 삽입 연산이라면
					cout << min({ weightDist[i - 1][j], weightDist[i - 1][j - 1], weightDist[i][j - 1] }) << " ";
					path.push_back("삽입비용:0.7"); // 삽입 연산을 push
					cout << i << " " << j << "삽입1\n";
					//cout << source[j - 1] << " " << target[i - 1] << "\n";
					i -= 1; // 인덱스 가로 --
				}
				else if (min(weightDist[i - 1][j], min(weightDist[i - 1][j - 1], weightDist[i][j - 1])) == weightDist[i][j - 1]) // 각 인덱스에 해당하는 값이 다르면서 최소 값이 삭제 연산이라면
				{
					path.push_back("삭제비용:0.5"); // 삭제 연산을 push
					cout << i << " " << j << "삭제1\n";
					//cout << source[j - 1] << " " << target[i - 1] << "\n";
					j -= 1; // 세로 인덱스 --
				}
				else {
					path.push_back("교체비용:0.3"); // 가장 작은 값이 교체 연산이라면 교체연산을 push
					cout << i << " " << j << "교체1\n";
					//cout << source[j - 1] << " " << target[i - 1] << "\n";
					i -= 1;
					j -= 1;
				}
			}
		}
		if (j == 0 && i != 0) { //만약 세로줄이 인덱스가 0이라 삭제 연산의 경우가 존재하지 않는다면 삽입연산만 고려한다. 
			path.push_back("삽입비용:0.7");
			cout << i << " " << j << "삽입\n";
			cout << source[j] << " " << target[i] << "\n";
			i -= 1;
		}
		if (i == 0 && j != 0) { // 만약 가로줄의 인덱스가 0이라 삽입 연산의 경우가 존재하지 않는다면 삭제연산만 고려한다. 
			path.push_back("삭제비용:0.5");
			cout << i << " " << j << "삭제\n";
			cout << source[j] << " " << target[i] << "\n";
			j -= 1;
		}
		if (i == 0 && j == 0) break;
	}

	while (path.size() != 1) { // push한 벡터를 뒤에서부터 출력해준다. 
		cout << path.back() << ", ";
		path.pop_back();
	}
	cout << path.back() << ": Levenshtein Distance = " << weightDist[target.length()][source.length()];
}
//12171800 심정호
void pathKoreanPrint(wstring source, wstring target) { // 한글의 경우 한 글자당 2byte이기 때문에 따로 처리를 해준다. 
	int i = target.length(); // 문자열 비교를 위한 인덱스
	int j = source.length(); // 문자열 비교를 위한 인덱스
	int y = target.length() / 2; int x = source.length() / 2; // matrix이동을 위한 인덱스
	while (i >= 0 && j >= 0 && y >= 0 && x >= 0) // 만약 문자열과 matrix에서 다 0보다 크다면
	{
		if (i != 0 && j != 0 && y != 0 && x != 0) { // 다 0이 아닌 경우에는
			if (source[j - 1] == target[i - 1] && source[j - 2] == target[i - 2]) { // 한글의 한 글자가 같다면
				//cout << source[j - 1] << " " << target[i - 1] << "\n";
				cout << y << " " << x << "same\n";
				i -= 2; // 문자열의 인덱스는 2를 줄여준다. 한글의 byte는 2
				j -= 2;
				x -= 1; // matrix의 인덱스는 1을 줄여준다.
				y -= 1;
			}
			else
			{
				if (min(weightDist[y - 1][x], min(weightDist[y - 1][x - 1], weightDist[y][x - 1])) == weightDist[y - 1][x]) { // 같지 않은 경우에는 
					cout << min({ weightDist[y - 1][x], weightDist[y - 1][x - 1], weightDist[y][x - 1] }) << " ";
					path.push_back("삽입비용:0.7"); // 삽입 비용을 push해주고
					cout << y << " " << x << "삽입1\n";
					//cout << source[j - 1] << " " << target[i - 1] << "\n";
					i -= 2; // 문자 인덱스는 2를 줄이고
					y -= 1; // matrix인덱스는 1을 줄인다. 
				}
				else if (min(weightDist[y - 1][x], min(weightDist[y - 1][x - 1], weightDist[y][x - 1])) == weightDist[y][x - 1])
				{ // 만약 최소 값이 삭제 비용인 경우
					path.push_back("삭제비용:0.5"); // 삭제 비용을 push해주고
					cout << y << " " << x << "삭제1\n";
					//cout << source[j - 1] << " " << target[i - 1] << "\n";
					j -= 2; // 문자열의 인덱스를 2줄이고
					x -= 1; // matrix의 인덱스를 1 줄인다. 
				}
				else {
					path.push_back("교체비용:0.3"); // 만약 교체 비용이 최소라면 교체 비용을 push해주고
					cout << y << " " << x << "겨체1\n";
					//cout << source[j - 1] << " " << target[i - 1] << "\n";
					i -= 2; // 문자열의 인덱스를 2줄이고
					j -= 2;
					y -= 1; //matrix의 인덱스를 1씩 줄인다. 
					x -= 1;
				}
			}
		}
		if (x == 0 && y != 0) { // 만약 세로 인덱스가 0이라 삭제 비용이 존재하지 않는 경우 삽입 비용만 고려한다. 
			path.push_back("삽입비용:0.7");
			cout << y << " " << x << "삽입\n";
			//cout << source[j] << " " << target[i] << "\n";
			i -= 2;
			x -= 1;
		}
		if (y == 0 && x != 0) { // 만약 가로 인덱스가 0이라 삽입 비용이 존재하지 않는 경우 삭제 비용만 고려한다. 
			path.push_back("삭제비용:0.5");
			cout << y << " " << x << "삭제\n";
			//cout << source[j] << " " << target[i] << "\n";
			j -= 2;
			x -= 1;
		}
		if (i == 0 && j == 0) break;
	}

	while (path.size() != 1) { // push한 벡터를 뒤에서부터 출력해준다. 
		cout << path.back() << ", ";
		path.pop_back();
	}
	cout << path.back() << ": Levenshtein Distance = " << weightDist[target.length() / 2][source.length() / 2];
}
//12171800 심정호
void levenshetein(wstring input1, wstring input2) {
	for (int j = 1; j <= input1.size(); j++) {
		weightDist[0][j] = j;
	} // 초기화 삭제 거리 1
	for (int i = 1; i <= input2.size(); i++) {
		weightDist[i][0] = i;
	}//초기화 추가 거리 1
	for (int i = 1; i <= input2.size(); i++) {
		for (int j = 1; j <= input1.size(); j++) {
			if (input2[i - 1] == input1[j - 1]) weightDist[i][j] = weightDist[i - 1][j - 1]; // 문자가 같다면 대각선에 있던 내용을 그대로 가져온다. 
			else weightDist[i][j] = min(weightDist[i - 1][j - 1] + 1, min(weightDist[i][j - 1] + 1, weightDist[i - 1][j] + 1)); // 문자가 서로 다르다면 대각선 왼쪽 위 중 가장 작은 값을 가져온다. 
		}
	}
	printweightDist(input1, input2);
	//pathPrint(input1, input2);
	//return 0;
}
//12171800 심정호
int customWeightLevenshetein(wstring input1, wstring input2) {
	for (int j = 1; j <= input1.length(); j++) {
		weightDist[0][j] = weightDist[0][j - 1] + 0.5;
	} // 초기화 삭제 거리  0.5
	for (int i = 1; i <= input2.length(); i++) {
		weightDist[i][0] = weightDist[i - 1][0] + 0.7;
	}//초기화 삽입 거리 0.7
	for (int i = 1; i <= input2.length(); i++) {
		for (int j = 1; j <= input1.length(); j++) {
			if (input2[i - 1] == input1[j - 1]) weightDist[i][j] = weightDist[i - 1][j - 1]; // 문자가 같다면 대각선에 있던 값을 그대로 가져온다. 
			else {
				weightDist[i][j] = min(weightDist[i - 1][j - 1] + 0.3, min(weightDist[i][j - 1] + 0.5, weightDist[i - 1][j] + 0.7)); // 문자가 다르다면 가중치를 더해준 후의 왼쪽 대각선 위의 값 중 가장 작은 값을 가져온다.
			}
		}
	}
	pathPrint(input1, input2); // 경로를print
	cout << "\n";
	printweightDist(input1, input2);// weight matrix를 print해준다. 
	return weightDist[input1.length()][input2.length()];
}
//12171800 심정호
int KoreanKevenshetein(wstring input1, wstring input2) { // 한글은 2byte이기 때문에 따로 처리해주어야한다. 
	for (int j = 1; j <= input1.size() / 2; j++) {
		weightDist[0][j] = j;
	} // 초기화 삭제 거리 1
	for (int i = 1; i <= input2.size() / 2; i++) {
		weightDist[i][0] = i;
	}//초기화 추가 거리 1
	for (int i = 1; i <= input2.size() / 2; i++) {
		for (int j = 1; j <= input1.size() / 2; j++) {
			if (input2[i * 2 - 2] == input1[j * 2 - 2] && input2[i * 2 - 1] == input1[j * 2 - 1]) { //한글은 2byte이기 때문에 인덱스를 2 씩 줄여가며 비교를 해주어야한다. 
				cout << input2[i * 2 - 2] << input1[j * 2 - 2] << " " << input2[i * 2 - 1] << input1[j * 2 - 1] << "\n";
				weightDist[i][j] = weightDist[i - 1][j - 1]; // 만약 문자가 같다면 대각선의 값을 그대로 가져온다. 
			}
			else weightDist[i][j] = min(weightDist[i - 1][j - 1] + 1, min(weightDist[i][j - 1] + 1, weightDist[i - 1][j] + 1)); // 문자가 서로 다르다면 왼쪽 대각선 위의 값 중 가중치를 더한 후의 값이 가장 작은 것을 가져온다. 
		}
	}
	for (int i = 0; i <= input2.size() / 2; i++) {
		for (int j = 0; j <= input1.size() / 2; j++) {
			cout << weightDist[i][j];
		}
		cout << "\n"; // weight matrix출력
	}
	pathKoreanPrint(input1, input2);// 한글인 경우 비용을 계산해준다. 

	return 0;
}
//12171800 심정호
int KoreanweightKevenshetein(wstring input1, wstring input2) { // 한글은 2byte이기 때문에 따로 처리해주어야한다. 
	for (int j = 1; j <= input1.size() / 2; j++) {
		weightDist[0][j] = weightDist[0][j - 1] + 0.5;
	} // 초기화 삭제 거리
	for (int i = 1; i <= input2.size() / 2; i++) {
		weightDist[i][0] = weightDist[i - 1][0] + 0.7;
	}//초기화 추가 거리
	for (int i = 1; i <= input2.size() / 2; i++) {
		for (int j = 1; j <= input1.size() / 2; j++) {
			if (input2[i * 2 - 2] == input1[j * 2 - 2] && input2[i * 2 - 1] == input1[j * 2 - 1]) { //한글은 2byte이기 때문에 인덱스를 2 씩 줄여가며 비교를 해주어야한다. 
				weightDist[i][j] = weightDist[i - 1][j - 1]; // 만약 문자가 같다면 대각선의 값을 그대로 가져온다. 
			}
			else weightDist[i][j] = min(weightDist[i - 1][j - 1] + 0.3, min(weightDist[i][j - 1] + 0.5, weightDist[i - 1][j] + 0.7)); // 문자가 서로 다르다면 왼쪽 대각선 위의 값 중 가중치를 더한 후의 값이 가장 작은 것을 가져온다. 
		}
	}
	//cout << weightDist[input2.size() / 2][input1.size() / 2] << "\n";
	for (int i = 0; i <= input2.size() / 2; i++) {
		for (int j = 0; j <= input1.size() / 2; j++) {
			cout << weightDist[i][j] << " ";
		}
		cout << "\n"; // weight matrix출력
	}

	pathKoreanPrint(input1, input2);// 한글인 경우 비용을 계산해준다. 

	return 0;
}
int main() {
	wcin >> input1 >> input2;
	cout << "LevenStein >>>>>>>>>>>>>>>>>>\n";
	//levenshetein(input1, input2); // 영어 데이터 가중치 1
	customWeightLevenshetein(input1, input2); // 영어 데이터 가중치 서로 다름 data 1 , data2
	//KoreanKevenshetein(input1, input2); // 한글 데이터 가중치 1
	//KoreanweightKevenshetein(input1, input2); // 한글 데이터 가중치 서로 다름 data3의 경우
}