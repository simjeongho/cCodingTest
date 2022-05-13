#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 5;
int k = 3;
int a[5] = { 1,2,3,4,5 };
vector<int> b;
void print(vector<int> b) {
	for (int i = 0; i < b.size(); i++) {
		cout << b[i] << " ";
	}
	cout << "\n";
}

void combi(int start, vector<int> b) {
	if (b.size() == k) {
		print(b);
		cout << "return\n";
		return;
	}// ±âÀú»ç·Ê
	for (int i = start + 1; i < n; i++) {
		cout << "b.push_back " << i << "\n";
		b.push_back(i);
		combi(i, b);
		cout << "b.pop\n";
		b.pop_back();
		cout << "For return\n";
	}
}

int main() {
	combi(-1, b);
}