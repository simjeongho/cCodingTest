#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <tchar.h>
using namespace std;
//12171800 ����ȣ
wstring input1, input2;
wstring kosource, kotarget;
double weightDist[1001][1001];
vector <string> path; // path�� �ش��ϴ� ������ ������ ���� 
void printweightDist(wstring input1, wstring input2) { // weight distance�� ������ִ� �Լ� 
	for (int i = 0; i <= input2.length(); i++) {
		for (int j = 0; j <= input1.length(); j++) {
			cout << weightDist[i][j] << " ";
		}
		cout << "\n";
	}
}
//12171800 ����ȣ
void pathPrint(wstring source, wstring target) {
	int i = target.length();// target �ε��� + 1�� �ش���
	int j = source.length(); // source �� �ε��� + 1�� �ش��� 
	while (i >= 0 && j >= 0) // dist�迭�� �ε����� 0���� Ŭ ���� �����Ѵ�. 
	{
		if (i != 0 && j != 0) { // ���Կ��� �������� ��ü���� �� ���� ����� ���� ��� ������ ��
			if (source[j - 1] == target[i - 1]) { // ���� �� �ε����� �ش��ϴ� ���� ���ٸ�
				//cout << source[j - 1] << " " << target[i - 1] << "\n";
				cout << i << " " << j << "same\n";
				i -= 1;// �׳� �밢������ �ö󰣴�. ��� 0
				j -= 1;
			}
			else
			{
				if (min(weightDist[i - 1][j], min(weightDist[i - 1][j - 1], weightDist[i][j - 1])) == weightDist[i - 1][j]) { // ������ �� �ε����� �ش��ϴ� ���� �ٸ��鼭 �ּ� ���� ���� �����̶��
					cout << min({ weightDist[i - 1][j], weightDist[i - 1][j - 1], weightDist[i][j - 1] }) << " ";
					path.push_back("���Ժ��:0.7"); // ���� ������ push
					cout << i << " " << j << "����1\n";
					//cout << source[j - 1] << " " << target[i - 1] << "\n";
					i -= 1; // �ε��� ���� --
				}
				else if (min(weightDist[i - 1][j], min(weightDist[i - 1][j - 1], weightDist[i][j - 1])) == weightDist[i][j - 1]) // �� �ε����� �ش��ϴ� ���� �ٸ��鼭 �ּ� ���� ���� �����̶��
				{
					path.push_back("�������:0.5"); // ���� ������ push
					cout << i << " " << j << "����1\n";
					//cout << source[j - 1] << " " << target[i - 1] << "\n";
					j -= 1; // ���� �ε��� --
				}
				else {
					path.push_back("��ü���:0.3"); // ���� ���� ���� ��ü �����̶�� ��ü������ push
					cout << i << " " << j << "��ü1\n";
					//cout << source[j - 1] << " " << target[i - 1] << "\n";
					i -= 1;
					j -= 1;
				}
			}
		}
		if (j == 0 && i != 0) { //���� �������� �ε����� 0�̶� ���� ������ ��찡 �������� �ʴ´ٸ� ���Կ��길 ����Ѵ�. 
			path.push_back("���Ժ��:0.7");
			cout << i << " " << j << "����\n";
			cout << source[j] << " " << target[i] << "\n";
			i -= 1;
		}
		if (i == 0 && j != 0) { // ���� �������� �ε����� 0�̶� ���� ������ ��찡 �������� �ʴ´ٸ� �������길 ����Ѵ�. 
			path.push_back("�������:0.5");
			cout << i << " " << j << "����\n";
			cout << source[j] << " " << target[i] << "\n";
			j -= 1;
		}
		if (i == 0 && j == 0) break;
	}

	while (path.size() != 1) { // push�� ���͸� �ڿ������� ������ش�. 
		cout << path.back() << ", ";
		path.pop_back();
	}
	cout << path.back() << ": Levenshtein Distance = " << weightDist[target.length()][source.length()];
}
//12171800 ����ȣ
void pathKoreanPrint(wstring source, wstring target) { // �ѱ��� ��� �� ���ڴ� 2byte�̱� ������ ���� ó���� ���ش�. 
	int i = target.length(); // ���ڿ� �񱳸� ���� �ε���
	int j = source.length(); // ���ڿ� �񱳸� ���� �ε���
	int y = target.length() / 2; int x = source.length() / 2; // matrix�̵��� ���� �ε���
	while (i >= 0 && j >= 0 && y >= 0 && x >= 0) // ���� ���ڿ��� matrix���� �� 0���� ũ�ٸ�
	{
		if (i != 0 && j != 0 && y != 0 && x != 0) { // �� 0�� �ƴ� ��쿡��
			if (source[j - 1] == target[i - 1] && source[j - 2] == target[i - 2]) { // �ѱ��� �� ���ڰ� ���ٸ�
				//cout << source[j - 1] << " " << target[i - 1] << "\n";
				cout << y << " " << x << "same\n";
				i -= 2; // ���ڿ��� �ε����� 2�� �ٿ��ش�. �ѱ��� byte�� 2
				j -= 2;
				x -= 1; // matrix�� �ε����� 1�� �ٿ��ش�.
				y -= 1;
			}
			else
			{
				if (min(weightDist[y - 1][x], min(weightDist[y - 1][x - 1], weightDist[y][x - 1])) == weightDist[y - 1][x]) { // ���� ���� ��쿡�� 
					cout << min({ weightDist[y - 1][x], weightDist[y - 1][x - 1], weightDist[y][x - 1] }) << " ";
					path.push_back("���Ժ��:0.7"); // ���� ����� push���ְ�
					cout << y << " " << x << "����1\n";
					//cout << source[j - 1] << " " << target[i - 1] << "\n";
					i -= 2; // ���� �ε����� 2�� ���̰�
					y -= 1; // matrix�ε����� 1�� ���δ�. 
				}
				else if (min(weightDist[y - 1][x], min(weightDist[y - 1][x - 1], weightDist[y][x - 1])) == weightDist[y][x - 1])
				{ // ���� �ּ� ���� ���� ����� ���
					path.push_back("�������:0.5"); // ���� ����� push���ְ�
					cout << y << " " << x << "����1\n";
					//cout << source[j - 1] << " " << target[i - 1] << "\n";
					j -= 2; // ���ڿ��� �ε����� 2���̰�
					x -= 1; // matrix�� �ε����� 1 ���δ�. 
				}
				else {
					path.push_back("��ü���:0.3"); // ���� ��ü ����� �ּҶ�� ��ü ����� push���ְ�
					cout << y << " " << x << "��ü1\n";
					//cout << source[j - 1] << " " << target[i - 1] << "\n";
					i -= 2; // ���ڿ��� �ε����� 2���̰�
					j -= 2;
					y -= 1; //matrix�� �ε����� 1�� ���δ�. 
					x -= 1;
				}
			}
		}
		if (x == 0 && y != 0) { // ���� ���� �ε����� 0�̶� ���� ����� �������� �ʴ� ��� ���� ��븸 ����Ѵ�. 
			path.push_back("���Ժ��:0.7");
			cout << y << " " << x << "����\n";
			//cout << source[j] << " " << target[i] << "\n";
			i -= 2;
			x -= 1;
		}
		if (y == 0 && x != 0) { // ���� ���� �ε����� 0�̶� ���� ����� �������� �ʴ� ��� ���� ��븸 ����Ѵ�. 
			path.push_back("�������:0.5");
			cout << y << " " << x << "����\n";
			//cout << source[j] << " " << target[i] << "\n";
			j -= 2;
			x -= 1;
		}
		if (i == 0 && j == 0) break;
	}

	while (path.size() != 1) { // push�� ���͸� �ڿ������� ������ش�. 
		cout << path.back() << ", ";
		path.pop_back();
	}
	cout << path.back() << ": Levenshtein Distance = " << weightDist[target.length() / 2][source.length() / 2];
}
//12171800 ����ȣ
void levenshetein(wstring input1, wstring input2) {
	for (int j = 1; j <= input1.size(); j++) {
		weightDist[0][j] = j;
	} // �ʱ�ȭ ���� �Ÿ� 1
	for (int i = 1; i <= input2.size(); i++) {
		weightDist[i][0] = i;
	}//�ʱ�ȭ �߰� �Ÿ� 1
	for (int i = 1; i <= input2.size(); i++) {
		for (int j = 1; j <= input1.size(); j++) {
			if (input2[i - 1] == input1[j - 1]) weightDist[i][j] = weightDist[i - 1][j - 1]; // ���ڰ� ���ٸ� �밢���� �ִ� ������ �״�� �����´�. 
			else weightDist[i][j] = min(weightDist[i - 1][j - 1] + 1, min(weightDist[i][j - 1] + 1, weightDist[i - 1][j] + 1)); // ���ڰ� ���� �ٸ��ٸ� �밢�� ���� �� �� ���� ���� ���� �����´�. 
		}
	}
	printweightDist(input1, input2);
	//pathPrint(input1, input2);
	//return 0;
}
//12171800 ����ȣ
int customWeightLevenshetein(wstring input1, wstring input2) {
	for (int j = 1; j <= input1.length(); j++) {
		weightDist[0][j] = weightDist[0][j - 1] + 0.5;
	} // �ʱ�ȭ ���� �Ÿ�  0.5
	for (int i = 1; i <= input2.length(); i++) {
		weightDist[i][0] = weightDist[i - 1][0] + 0.7;
	}//�ʱ�ȭ ���� �Ÿ� 0.7
	for (int i = 1; i <= input2.length(); i++) {
		for (int j = 1; j <= input1.length(); j++) {
			if (input2[i - 1] == input1[j - 1]) weightDist[i][j] = weightDist[i - 1][j - 1]; // ���ڰ� ���ٸ� �밢���� �ִ� ���� �״�� �����´�. 
			else {
				weightDist[i][j] = min(weightDist[i - 1][j - 1] + 0.3, min(weightDist[i][j - 1] + 0.5, weightDist[i - 1][j] + 0.7)); // ���ڰ� �ٸ��ٸ� ����ġ�� ������ ���� ���� �밢�� ���� �� �� ���� ���� ���� �����´�.
			}
		}
	}
	pathPrint(input1, input2); // ��θ�print
	cout << "\n";
	printweightDist(input1, input2);// weight matrix�� print���ش�. 
	return weightDist[input1.length()][input2.length()];
}
//12171800 ����ȣ
int KoreanKevenshetein(wstring input1, wstring input2) { // �ѱ��� 2byte�̱� ������ ���� ó�����־���Ѵ�. 
	for (int j = 1; j <= input1.size() / 2; j++) {
		weightDist[0][j] = j;
	} // �ʱ�ȭ ���� �Ÿ� 1
	for (int i = 1; i <= input2.size() / 2; i++) {
		weightDist[i][0] = i;
	}//�ʱ�ȭ �߰� �Ÿ� 1
	for (int i = 1; i <= input2.size() / 2; i++) {
		for (int j = 1; j <= input1.size() / 2; j++) {
			if (input2[i * 2 - 2] == input1[j * 2 - 2] && input2[i * 2 - 1] == input1[j * 2 - 1]) { //�ѱ��� 2byte�̱� ������ �ε����� 2 �� �ٿ����� �񱳸� ���־���Ѵ�. 
				cout << input2[i * 2 - 2] << input1[j * 2 - 2] << " " << input2[i * 2 - 1] << input1[j * 2 - 1] << "\n";
				weightDist[i][j] = weightDist[i - 1][j - 1]; // ���� ���ڰ� ���ٸ� �밢���� ���� �״�� �����´�. 
			}
			else weightDist[i][j] = min(weightDist[i - 1][j - 1] + 1, min(weightDist[i][j - 1] + 1, weightDist[i - 1][j] + 1)); // ���ڰ� ���� �ٸ��ٸ� ���� �밢�� ���� �� �� ����ġ�� ���� ���� ���� ���� ���� ���� �����´�. 
		}
	}
	for (int i = 0; i <= input2.size() / 2; i++) {
		for (int j = 0; j <= input1.size() / 2; j++) {
			cout << weightDist[i][j];
		}
		cout << "\n"; // weight matrix���
	}
	pathKoreanPrint(input1, input2);// �ѱ��� ��� ����� ������ش�. 

	return 0;
}
//12171800 ����ȣ
int KoreanweightKevenshetein(wstring input1, wstring input2) { // �ѱ��� 2byte�̱� ������ ���� ó�����־���Ѵ�. 
	for (int j = 1; j <= input1.size() / 2; j++) {
		weightDist[0][j] = weightDist[0][j - 1] + 0.5;
	} // �ʱ�ȭ ���� �Ÿ�
	for (int i = 1; i <= input2.size() / 2; i++) {
		weightDist[i][0] = weightDist[i - 1][0] + 0.7;
	}//�ʱ�ȭ �߰� �Ÿ�
	for (int i = 1; i <= input2.size() / 2; i++) {
		for (int j = 1; j <= input1.size() / 2; j++) {
			if (input2[i * 2 - 2] == input1[j * 2 - 2] && input2[i * 2 - 1] == input1[j * 2 - 1]) { //�ѱ��� 2byte�̱� ������ �ε����� 2 �� �ٿ����� �񱳸� ���־���Ѵ�. 
				weightDist[i][j] = weightDist[i - 1][j - 1]; // ���� ���ڰ� ���ٸ� �밢���� ���� �״�� �����´�. 
			}
			else weightDist[i][j] = min(weightDist[i - 1][j - 1] + 0.3, min(weightDist[i][j - 1] + 0.5, weightDist[i - 1][j] + 0.7)); // ���ڰ� ���� �ٸ��ٸ� ���� �밢�� ���� �� �� ����ġ�� ���� ���� ���� ���� ���� ���� �����´�. 
		}
	}
	//cout << weightDist[input2.size() / 2][input1.size() / 2] << "\n";
	for (int i = 0; i <= input2.size() / 2; i++) {
		for (int j = 0; j <= input1.size() / 2; j++) {
			cout << weightDist[i][j] << " ";
		}
		cout << "\n"; // weight matrix���
	}

	pathKoreanPrint(input1, input2);// �ѱ��� ��� ����� ������ش�. 

	return 0;
}
int main() {
	wcin >> input1 >> input2;
	cout << "LevenStein >>>>>>>>>>>>>>>>>>\n";
	//levenshetein(input1, input2); // ���� ������ ����ġ 1
	customWeightLevenshetein(input1, input2); // ���� ������ ����ġ ���� �ٸ� data 1 , data2
	//KoreanKevenshetein(input1, input2); // �ѱ� ������ ����ġ 1
	//KoreanweightKevenshetein(input1, input2); // �ѱ� ������ ����ġ ���� �ٸ� data3�� ���
}