# DFS, BFS

DFS와 BFS는 그래프의 탐색 과정에서 사용된다. 
- 미로
- 테두리 

등등 그래프를 직접 탐색하여 조건에 맞는 코드를 구현하는 데에 사용된다. 

DFS와 BFS모두 그래프를 탐색하는 만큼 방향 배열과 방문 여부 배열은 필수이다. 
---
## 1. DFS
```
int ny, nx; // 다음 탐색 할 배열의 인덱스에 해당한다.
int dy[4] = {0, 1, 0, -1}; // y축으로의 방향 만약 대각선을 포함한다면 추가해준다.
int dx[4] = {-1, 0. 1, 0}; // x축으로의 방향 대각선을 포함한다면 추가해준다. 
int R,C //map의 크기
int map[100][100];  
int visited[100][100] // map의 크기와 같은 방문 여부 배열을 선언

void dfs(int y, int x) {
    visited[y][x] = 1;

    for(int i=0 ; i < 4; i++) {
        ny = dy[i] + y;
        nx = dx[i] + x;
        
        if(ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx])continue;
        //해야하는 작업
        dfs(ny, nx); // 재귀의 형태로 구현 ny, nx로부터 다시 dfs 시작
    }
}
```
---
## 2. BFS
```
#include <queue>

int ny, nx;
int R,C;
int map[100][100];
int visited[100][100];
int dy[4] = {0,1,0,-1};
int dx[4] = {-1,0,1,0};

queue<pair<int, int>> q;

void BFS(int y, int x) {
    visited[y][x] = 1;
    q.push({y,x});
    while(q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for(int i=0;i < 4; i++){
            ny = dy[i] + y;
            nx = dx[i] + x;
            if(ny < 0 || nx < 0 || ny >= R || nx >= C || visited[y][x]) continue; // 조건 처리
            q.push({ny, nx});
        }
    }
}
```
---
### 백준_2636

이 문제의 핵심은 테두리의 조건을 어떻게 할 것인가 였다. 
내가 가장 고민했던 부분은 치즈안의 공간이었다. 처음에는 모든 칸을 탐색하며 밖인지 안인지를 판단해주려고 했지만 dfs를 통해 탐색하다가 만약 치즈를 만난다면 return해주는 방향으로도 테두리의 판단을 할 수 있었다. 

DFS는 깊이 우선 탐색이기 때문에 만약 치즈를 만난다면 탐색하던 경로 전체가 리턴이 되어버리므로 다른 root를 다시 탐색하기 때문이다. 

```
void solution(int y, int x)  {
	visited[y][x] = 1;
	if (cheese[y][x] == 1) {
		v.push_back({ y,x });
		return;
	}
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx]) continue; // �������
		solution(ny, nx);
	}
}
```
위의 코드처럼 dfs를 통해 탐색을 진행하다가 치즈를 만난다면 그 인덱스를 push_back해주고 return해준다. 그 이 후 테두리에 해당하는 인덱스에 대한 처리를 main함수에서 해주면 된다. 
---
### 백준_2638

위와 비슷한 문제지만 조건이 하나 추가되었다. 
바로 2면 이상이 공기에 노출되어야 사라진다는 것이다. 
위의 문제처럼 visited 배열을 통해 테두리를 구해두고 벡터에 테두리에 해당하는 인덱스들을 넣어주었다. 

그 후 그 인덱스들에 대해 다시 방향 벡터에 대한 for문을 돌면서 이 테두리가 과연 몇 면이 노출되어있는지 확인했다. 만약 2면 이상이라면 치즈를 cheese에서 삭제하고 전체 cheeseCnt또한 줄여주었다. 그 이후 cheeseCnt가 0이 되는 순간의 반복횟수를 출력해주면 된다. 
```
//탐색함수
void sol(int y, int x) {
	visited[y][x] = 1;
	if (cheese[y][x] == 1) {
		visited[y][x]++;
		v.push_back({ y, x });
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
		sol(ny, nx);
	}

}
//main함수 내에서의 flow 
while (1) {
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0); // visited map �ʱ�ȭ
		v.clear();
		sol(0, 0);
		for (auto a : v) {
			int cnt = 0;
			for (int i = 0; i < 4; i++) {
				int ny = a.first + dy[i];
				int nx = a.second + dx[i];
				if (visited[ny][nx] == 1) {
					cnt++; // 증가 시켜준다. 
					if (cnt >= 2) {// 두면 이상 만난다면 
						cheese[a.first][a.second] = 0;
						cheeseCnt--;
						break;
					}
					if (cheeseCnt == 0) break;
				}
			}
		}
		res++;
		if (cheeseCnt == 0) break;
	}	
```
---
## 백준_1068
이 문제는 여태 다른 dfs와는 다르게 직접 그래프를 구축한 후 dfs 탐색을 수행해야하는 문제였다. 이 문제에서 그래프는 트리 형태로 각 노드의 부모 노드가 입력으로 주어지게 된다. 그러면 어떻게 그래프의 형태를 나타내야 할까?

1. 자료구조 <vector>
우선 `vector`를 이용할 수 있겠다. `vector`의 배열을 만들어두고 각 노드의 부모 노드를 `vector`배열의 인덱스로 생각한다. 입력이 들어오면 해당 부모 노드에 해당하는 인덱스에 넣어준다. 
단, root에 해당하는 노드는 신경 써주어야한다. 
```
for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == -1) root = i;
		else adj[temp].push_back(i);
	}
```
2. `int` 반환 `dfs`
```
int dfs(int here) {
	int ret = 0; 
	int child = 0;
	for (int there : adj[here]) {
		if (there == r) continue;
		ret += dfs(there);
		child++;
	}
	if (child == 0) return 1;
	return ret;
}
```
이 문제에서 사용된 dfs는 다음과 같다. `iterator`를 통해 `vector`의 배열을 탐색하면서 만나게 되는 원소와 같은 인덱스로 가서 다시 탐색한다. 탐색이 진행된다는 것은 `node`의 `child`가 존재한다는 것이니 `child++`해주고 `child`가 0인 경우가 `leaf node`에 해당하므로 개수를 세어준다.
