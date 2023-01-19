#pragma warning (disable:4996)
#include <cstdio>
#include <climits> // INT MAX
#include <vector>
#include <queue>
using namespace std;

struct n_t {
	int node, cost;

	inline bool operator<(const n_t& ref) const {
		return this->cost > ref.cost; // min heap���� ����� ���� �ε�ȣ ������ �ٲ���Ѵ�.
	}
}; // c++���� struct�� class�� ���� 
/*
	������ ����ϴ�. 
	�� �ϳ��� ����
	struct�� ���������ڰ� �⺻���� public�̰� class�� private�̴�.
	struct�� ��� �� ������� �޸� ���� �ּҰ� �ٸ����� union�� ��� �� ������� ���� �ּҰ� ��� �����ϴ�.
*/
int V, E, K;
vector<n_t> AL[20001];
int visited[20001]; // �� ������ ���� �ִ� ��� ����� ���� (�ſ� ū ���� ��� �� �湮)�ſ� ū �� ��������� 

int main() {
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		AL[u].push_back({ v,w });
	}
	for (int i = 1; i <= V; i++) {
		visited[i] = INT_MAX;// ���Ѵ�� �ʱ�ȭ
	}
	//Dijkstra
	//struct�� ������ �˷������ 
	//
	priority_queue <n_t> PQ; //�湮�� ���� ���� cost
	visited[K] = 0;
	PQ.push({ K,0 });
	while (!PQ.empty()) {
		n_t curr = PQ.top();
		PQ.pop();
		for (n_t next : AL[curr.node]) {
			int cost = visited[curr.node] + next.cost; // ���� �ڽ�Ʈ �����
			if (cost < visited[next.node]) {
				//�湮�������� ���Ѵ�� �ʱ�ȭ�� �Ǿ����� 
				//�̹湮 ���� Ȯ��
				visited[next.node] = cost;  // ���� �� PQ�� �ǹ̾��� ���� ���� �Ͱ� �Ǵ� ���� Ƚ���� �氨 
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
//	//�̰��� min heap���� ����� �ʹ�. 
//	//1. ���� ������ ��� (������ �� ���� ����)
//	//���� �� ���������� �ְ� �� ���� -�� �ٿ��� ������. 
//	pq.push(-1);
//	pq.push(-3);
//	pq.push(-2);
//	int val = -pq.top();
//
//	//2. formal�� ���
//	// std::less < , std::greater > 
//	std::priority_queue<int,std::vector<int> ,  greater<int>()> pq2;
//
//}
