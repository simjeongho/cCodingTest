#include <iostream>
#include <map>
#include <vector>

using namespace std;

int M;
int N;
int mat;
vector <int> v;
int res;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> mat;
		v.push_back(mat);
	}
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				if (v[i] + v[j] == M) {
					res++;
				}

			}
		}
		cout << res << "\n";
	return 0;
}