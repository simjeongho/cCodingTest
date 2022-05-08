#include <iostream>
#include <String>
#include <fstream>
#include <sstream>
using namespace std;
int Num = 95; // Ư������, ����, ���ĺ� �� �ҹ��� ���� 
int skip[95]; // skip �迭
void initSkip(string p) // skip �迭�� ����� �Լ�
{
	int i;
	int M = p.length(); // ������ ����
	for (i = 0; i < Num; i++) {
		skip[i] = M;//���� ������ ���̷� skip �迭 �ʱ�ȭ
	}
	for (i = 0; i < M; i++) {
		skip[p[i] - 32] = M - i - 1; // �����̽� �� == ���鿡 �ش��ϴ� �ƽ�Ű �ڵ尡 32���̰� ������ ��°����� ���ڿ� �ƽ�Ű�ڵ� �� ���� ���� ���� ��
	}
}

int MisChar(string p, string t) {
	int M = p.length(); // M�� ������ ����
	int N = t.length(); // N�� ������ ���� 
	int k;
	int i = M - 1; // �ڿ��� ���� ����
	int j = M - 1; // �ڿ��� ���� ���� 
	initSkip(p); // �Է¹��� ���Ͽ� ���� skip �迭�� �����. 
	while (i < N) { // �Է¹��� �ؽ�Ʈ�� ��� Ž���� ������
		for (i, j = M - 1; j >= 0; i -= 1, j -= 1) { // �ؽ�Ʈ�� ������ ���Ѵ�.
			while (t[i] != p[j]) {
				k = skip[t[i] - 32]; // char���� �ƽ�Ű �ڵ�ν� �迭�� ���� ������ �ռ� �ʱ�ȭ���� skip�迭�� ���� �ϱ� ���� 32�� ���ش�. 
				if (M - j > k) i = i + M - j;
				else i = i + k;
				if (i >= N) return N; // ������ �׳� �ؽ�Ʈ ������ �������� �����Ѵ�. 
				j = M - 1;//���� �ε��� �ٽ� �ʱ�ȭ 
			}

		}
		cout << "found at " << i + 1 << "\n"; // ���� ��ġ�� ��ȯ
		i = i + M+ 1; //�ؽ�Ʈ�� �ε����� ������ ã�� �� + ���� ���� +1�� �Ͽ� ������ ���� ������ ���ϱ� �����Ѵ�. 
	}
		
}

int main() {
	string pattern;
	cout << "�˻��� ���ڿ��� �Է��ϼ���" << "\n";
	getline(cin, pattern); // ��ĭ ���� string �Է� �ޱ� 
	ifstream file("RFC2616_modified.txt"); // ������ �д´�.
	istreambuf_iterator<char> begin(file), end; // ���� ��ü�� �� ���� �д´�. 
	string text = string(begin, end);// misChar �Լ��� �Ķ���Ͱ� string ���̹Ƿ� string���� �������ش�. 
	cout << text;

	MisChar(pattern, text);
	cout << "pattern : " << pattern << "\n";
	for (int i = 0; i < Num; i++) {
		cout << skip[i] << " ";
	}
	cout << "\n";
}