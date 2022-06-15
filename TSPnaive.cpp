#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <time.h>

using namespace std;

int n;
//가중치를 저장하기 위한 배열
int dist[16][16];
int TSPnaive(vector<int> path, vector<bool> visited, int len) {
	//모든 도시 다 방문했을 때
	if (path.size() == n) return len + dist[path.back()][0];
	int ret = 987654321;

	for (int next = 0; next < n; next++) {
		//방문했다면 패스
		if (visited[next] == true) continue;

		int cur = path.back(); //가장 뒤에 있는 도시 방문
		path.push_back(next); //  next를 푸쉬한다. 
		visited[next] = true; // next 방문 처리를 한다.
		ret = min(ret, TSPnaive(path, visited, len + dist[cur][next])); // 재귀함수를 이용해서 처리한다. 
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
	vector<int> path(1, 0); // 경로를 저장할 벡터, 시작 도시 0번 도시 선택
	vector<bool> visited(n, false); // 방문 여부를 받을 벡터 , false로초기화 
	visited[0] = true;//0 방문 
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
