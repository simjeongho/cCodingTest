#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <time.h>

using namespace std;

int n;
//����ġ�� �����ϱ� ���� �迭
int dist[16][16];
int TSPnaive(vector<int> path, vector<bool> visited, int len) {
	//��� ���� �� �湮���� ��
	if (path.size() == n) return len + dist[path.back()][0];
	int ret = 987654321;

	for (int next = 0; next < n; next++) {
		//�湮�ߴٸ� �н�
		if (visited[next] == true) continue;

		int cur = path.back(); //���� �ڿ� �ִ� ���� �湮
		path.push_back(next); //  next�� Ǫ���Ѵ�. 
		visited[next] = true; // next �湮 ó���� �Ѵ�.
		ret = min(ret, TSPnaive(path, visited, len + dist[cur][next])); // ����Լ��� �̿��ؼ� ó���Ѵ�. 
		visited[next] = false;
		path.pop_back();
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}
	vector<int> path(1, 0); // ��θ� ������ ����, ���� ���� 0�� ���� ����
	vector<bool> visited(n, false); // �湮 ���θ� ���� ���� , false���ʱ�ȭ 
	visited[0] = true;//0 �湮 
	clock_t start, finish;
	double duration;
	start = clock();
	double ret = TSPnaive(path, visited, 0);
	finish = clock();
	duration = (double)(finish - start)/ CLOCKS_PER_SEC;
	cout << ret << endl;
	cout << "duration: " << duration;
}

/*4
0 2 9 1000
1 0 6 4
1000 7 0 8
6 3 1000 0*/
