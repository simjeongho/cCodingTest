#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cstdlib>
using namespace std;
int n; // 가로 세로 길이
vector<pair<int, int>> chicken, home; //치킨 집, 집 인덱스 저장
int map[55][55];
int m;// 최적화 된 치킨 집의 개수
int totaldist = 0;
int result = 100000;
void print(vector<pair<int, int>> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}
int combi(int start, vector<pair<int, int>> v) {
		if (v.size() == m) {
			totaldist = 0;
			//print(chicken);
			for (int i = 0; i < home.size(); i++) {
				int dist = 0;
				int min = 1000000;
				for (int u = 0; u < v.size(); u++) {// 선택된 모든 치킨집을 돌면서 집과의 거리를 구한 후 최소값을 구하고 누적합을 구한다. 
					dist = abs(v[u].first - home[i].first) + abs(v[u].second - home[i].second);
					//cout << "dist : " << dist << "\n";
					if (dist < min) min = dist;
					//cout << "min " << min << "\n";
				}
				totaldist += min;
				//cout << "total dist : " << totaldist << "\n";
				//cout << "\n\n";	
			}
			if (result > totaldist) result = totaldist;
			return 0;
		}
		for (int r = start+1; r < chicken.size(); r++) {
			v.push_back(chicken[r]);
			combi(r, v);
			v.pop_back();
		}
		return result;
	
}
int main() {
	vector<pair<int, int>> v;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	} // 입력 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 1) {
				home.push_back({ i,j });
			}
			if (map[i][j] == 2) {
				chicken.push_back({i, j});
			}
		}
	}
	combi(-1, v);
	cout << result << "\n";
}



