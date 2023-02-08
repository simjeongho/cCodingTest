/*
	���� �б�
	������ NxN
	��ü���� P ���� K �������� . �� �������� ���� ����
	����� �ϳ����� P���� ���� 
	���� ���� �밢������ ���� 
	������ ������ ����ϰ� �ٽ� ���ƿ;��Ѵ�. 

	�Ƿε��� �湮�� ĭ �� ���� ���� ���� ���� ���� �� ���� 
	���� ���� �Ƿε��� ��� ���� ����� �Ϸ��� ��� �ؾ��ϴ°�?

	���� ������ ��
	����ġ�� �����Ѵ�. 
	BFS�� �ִ� ��θ� Ž���ϴ� ���� �ƴ� �� ���� 
	BFS�� DP�� �̿��Ͽ� �ּ��� �Ƿε��� ����ϸ� �̵��ؾ��� �� ����. 
	2. ���� Ž�� �����ΰ� 
		-> �׷����� break������ �־���Ѵ�. 
		-> �Դ� ĭ�� �ٽ� ���ư��� �Ǵ°�
		-> �Ǵ� �� ����. �׷��� �� ������ ���� ��ü���� ��� ������ �κ� ���� �� �ִ� - �ּҰ� ���� �۾����� ��
	1. ���� �ε����� �����Ѵ�. 
	�����θ� ���ƴٴϴٰ�

	�ڿ� �� ���� 
	���� �ε����� 2�̻� ���̳��� �� ���� ĭ���� �̵��� �� �ִ� ĭ �� ���� ���� ���� ��´�. 
	1. ���� �ε����� ��� �˾ƾ��Ѵ�. 
	2. ���� �ε������� ���� �ε������� �����Ѵ�. 
	3. ���� 1�� ���̰� ���ٸ� �����θ� ���ƴٳ൵ �ȴ�. 
	4. 2�̻� ���̰� ���ٸ� �� ���̳� ���� �ش��ϴ� ���� Ž���Ͽ� ���� ���� ������ ��� �Ѵ�. 
	5. ���� �ε��� ���� �ε��� ������ ���� �� 1�� ���̰� ���ٸ� ������ ��

	ex)
	K.P
	...
	K.K
	3 3 4
	9 5 9
	8 3 7

	(0,0) , (0,2) , (2,0) , (2,2)
	���� �ε��� ����
	(0,0,2,2) -> �ȵȴ�. 1�� �־����
	���� �ε��� ����
	(0,0,2,2) -> 
	(0,1)�� �̾��� ���� ����. (1.0)�� �Ұ��ϴ�. 
	���� �� ���� �� �� �̾�����Ѵ�.


	Ǯ��
	-> �Ƿε��� ������ �߿��ϴ�.
	-> bfs�� �������� 
	-> �Ƿε��� ������ �����ϰ�(��������) bfs�� ������. ������ ���������� ������ �����Ѵ�.
	-> ���� ��� ���� �湮�Ѵٸ� ���Ѵ�.
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
bool visited[MAX][MAX]; // �湮 �迭
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
	//�� ���� 
	auto mxit = v.begin();
	auto mnit = v.begin();
	while (true) {
		int mxv = *mxit;
		int mnv = *mnit;

		if (mxv < dist[starty][startx]) {
			mxit++;
			continue; // �ִ� ���� ���� ������ �̵� 
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				visited[i][j] = 0; // �湮 �迭 �ʱ�ȭ
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
			mnit++; // �ּ� ���� ��������.
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