#pragma warning (disable:4996)
#include <cstdio>
#include <climits> // INT MAX
#include <vector>
#include <queue>
using namespace std;

struct n_t {
	int node, cost;

	inline bool operator<(const n_t& ref) const {
		return this->cost > ref.cost; // min heap으로 만들기 위해 부등호 방향을 바꿔야한다.
	}
}; // c++에서 struct와 class의 차이 
/*
	완전히 비슷하다. 
	단 하나의 차이
	struct는 접근제어자가 기본으로 public이고 class는 private이다.
	struct의 경우 각 멤버들의 메모리 시작 주소가 다르지만 union의 경우 각 멤버들의 시작 주소가 모두 동일하다.
*/
int V, E, K;
vector<n_t> AL[20001];
int visited[20001]; // 각 정점에 대한 최단 경로 비용을 저장 (매우 큰 값인 경우 미 방문)매우 큰 값 정해줘야함 

int main() {
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		AL[u].push_back({ v,w });
	}
	for (int i = 1; i <= V; i++) {
		visited[i] = INT_MAX;// 무한대로 초기화
	}
	//Dijkstra
	//struct비교 기준을 알려줘야함 
	//
	priority_queue <n_t> PQ; //방문한 노드와 누적 cost
	visited[K] = 0;
	PQ.push({ K,0 });
	while (!PQ.empty()) {
		n_t curr = PQ.top();
		PQ.pop();
		for (n_t next : AL[curr.node]) {
			int cost = visited[curr.node] + next.cost; // 누적 코스트 만들기
			if (cost < visited[next.node]) {
				//방문안했으면 무한대로 초기화가 되어있음 
				//미방문 정점 확인
				visited[next.node] = cost;  // 예약 값 PQ에 의미없는 값이 들어가는 것과 판단 로직 횟수를 경감 
				PQ.push({ next.node , cost });
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (visited[i] == INT_MAX) {
			puts("INF");
		}
		else {
			printf("%d\n", visited[i]);
		}
	}
	return 0;
}

//#include <functional>
//
//void foo() {
//	//max heap
//	std::priority_queue<int> pq;
//
//	pq.push(1);
//	pq.push(3);
//	pq.push(2);
//	int val = pq.top(); // 3
//	//이것을 min heap으로 만들고 싶다. 
//	//1. 가장 간단한 방법 (귀찮을 때 많이 쓰는)
//	//넣을 때 음수값으로 넣고 뺄 때도 -를 붙여서 꺼낸다. 
//	pq.push(-1);
//	pq.push(-3);
//	pq.push(-2);
//	int val = -pq.top();
//
//	//2. formal한 방법
//	// std::less < , std::greater > 
//	std::priority_queue<int,std::vector<int> ,  greater<int>()> pq2;
//
//}
