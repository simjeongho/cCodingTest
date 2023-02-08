/*
	문제 읽기
	마을은 NxN
	우체국은 P 집은 K 목초지는 . 각 지역별로 고도가 존재
	배달은 하나뿐인 P부터 시작 
	수평 수직 대각선까지 가능 
	마지막 편지를 배달하고선 다시 돌아와야한다. 

	피로도란 방문한 칸 중 가장 높은 곳과 낮은 곳의 고도 차이 
	가장 작은 피로도로 모든 집에 배달을 하려면 어떻게 해야하는가?

	내가 생각한 것
	가중치가 존재한다. 
	BFS로 최단 경로를 탐색하는 것은 아닌 것 같고 
	BFS와 DP를 이용하여 최소의 피로도를 기록하며 이동해야할 거 같다. 
	2. 완전 탐색 문제인가 
		-> 그러려면 break조건이 있어야한다. 
		-> 왔던 칸을 다시 돌아가도 되는가
		-> 되는 것 같다. 그러면 이 문제는 집과 우체국을 모두 포함한 부분 집합 중 최대 - 최소가 가장 작아지는 것
	1. 집의 인덱스를 저장한다. 
	집으로만 돌아다니다가

	뒤에 든 생각 
	집의 인덱스가 2이상 차이나면 그 다음 칸에서 이동할 수 있는 칸 중 가장 작은 것을 밟는다. 
	1. 집의 인덱스를 모두 알아야한다. 
	2. 가로 인덱스끼리 세로 인덱스끼리 정렬한다. 
	3. 만약 1씩 차이가 난다면 집으로만 돌아다녀도 된다. 
	4. 2이상 차이가 난다면 그 행이나 열에 해당하는 집을 탐색하여 가장 작은 발판을 밟게 한다. 
	5. 가로 인덱스 세로 인덱스 정렬을 했을 때 1씩 차이가 난다면 성공한 것

	ex)
	K.P
	...
	K.K
	3 3 4
	9 5 9
	8 3 7

	(0,0) , (0,2) , (2,0) , (2,2)
	가로 인덱스 정렬
	(0,0,2,2) -> 안된다. 1이 있어야함
	세로 인덱스 정렬
	(0,0,2,2) -> 
	(0,1)은 이어줄 수가 없다. (1.0)도 불가하다. 
	가로 와 세로 둘 다 이어줘야한다.


	풀이
	-> 피로도의 범위가 중요하다.
	-> bfs와 투포인터 
	-> 피로도의 범위를 설정하고(투포인터) bfs를 돌린다. 못가면 투포인터의 범위를 변경한다.
	-> 만약 모든 집을 방문한다면 비교한다.
*/
#pragma warning (disable:4996)

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 52
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int N;
vector <int> v;
char maps[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX]; // 방문 배열
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int house;
int starty, startx;
int ans = INF;
void input() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 'K') house++;
			if (maps[i][j] == 'P') {
				starty = i;
				startx = j;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> dist[i][j];
			v.push_back(dist[i][j]);
		}
	}
}
int cnt;
void dfs(int r, int c, int mx, int mn) {
	visited[r][c] = 1;
	if (maps[r][c] == 'K') { 
		cnt++; 
	}
	for (int i = 0; i < 8; i++) {
		int nr = r + dy[i];
		int nc = c + dx[i];
		if (nr <= 0 || nc <= 0 || nr > N || nc > N || visited[nr][nc]) continue;
		if (dist[nr][nc] > mx || dist[nr][nc] < mn) continue;
		dfs(nr, nc, mx, mn);
	}
}

void sol() {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	//고도 범위 
	auto mxit = v.begin();
	auto mnit = v.begin();
	while (true) {
		int mxv = *mxit;
		int mnv = *mnit;

		if (mxv < dist[starty][startx]) {
			mxit++;
			continue; // 최대 값을 시작 점까지 이동 
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				visited[i][j] = 0; // 방문 배열 초기화
			}
		}
		cnt = 0;
		dfs(starty, startx, mxv, mnv);
		//cout << "cnt:" << cnt << "\n";
		if (cnt != house) {
			mxit++;
			if (mxit == v.end()) break;
		}
		else {
			int tmp = *mxit - *mnit;
			ans = min(ans, tmp);
			mnit++; // 최소 값을 높여본다.
			//std::cout << "mxit : " << *mxit << "mnit" << *mnit << "\n";
			//cout << "ans : " << ans << "\n";
			if (*mnit > dist[starty][startx]) break;
			if (mnit == v.end()) break;
		}

	}
	std::cout << ans << "\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);
	input();
	sol();

	return 0;
}