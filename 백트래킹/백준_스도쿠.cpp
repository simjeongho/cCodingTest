#pragma warning (disable : 4996)

#include <cstdio>
#include <vector>
using namespace std;

int puzzle[10][10];
bool rows[10][10];
bool cols[10][10];
bool square[9][10];
//3가지의 방문 배열을 체크해야함 
vector<pair<int, int>> zeros;
void input() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &puzzle[i][j]);
			if (puzzle[i][j] == 0) zeros.push_back({ i,j }); //구해야하는 좌표 저장
			rows[i][puzzle[i][j]] = 1;
			cols[j][puzzle[i][j]] = 1;
			int squarenum = ((i / 3) * 3) + (j / 3);
			square[((i / 3) * 3) + (j / 3)][puzzle[i][j]] = 1; // 4각형 안의 방문 표시
		} //입력을 받는다. 
	}
}
int cnt;
void BackTrack(int idx) {
	if (idx == zeros.size() && cnt == 0) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", puzzle[i][j]);
			}
			printf("\n");
		}
		cnt++;
		idx--;
		return;
	}
	if (idx == zeros.size()) return;
		int squarenum = ((zeros[idx].first / 3) * 3) + (zeros[idx].second / 3);
		int ny = zeros[idx].first;
		int nx = zeros[idx].second;
		for (int i = 1; i <= 9; i++) {
			if (rows[ny][i] == 1) continue;
			if (cols[nx][i] == 1)continue;
			if (square[squarenum][i] == 1)continue;
			// 방문 배열들 체크
			puzzle[ny][nx] = i;// 다 통과된 i를 집어 넣는다.
			rows[ny][i] = 1;
			cols[nx][i] = 1;
			square[squarenum][i] = 1;
			BackTrack(idx + 1);
			rows[ny][i] = 0;
			cols[nx][i] = 0;
			square[squarenum][i] = 0;
		}
		return;
}
int main() {
	input();

	BackTrack(0);
	return 0;
}