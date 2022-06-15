#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX_NODE 17
#define MAX_COST 20000000000000
#define p pair<int, int>
using namespace std;

double getDist(int point1, int point2);
double tsp(int node, int visited);

int nodeNum;
double cost[MAX_NODE][MAX_NODE];
double dp[MAX_NODE][1 << MAX_NODE];
vector<p> vec;

int main() {
	cin >> nodeNum;

	for (int i = 1; i <= nodeNum; i++) {
		int x, y;
		cin >> x >> y;
		vec.push_back({ x, y });
	}

	for (int i = 1; i <= nodeNum; i++) {
		for (int j = 1; j <= nodeNum; j++) {
			cost[i][j] = getDist(i - 1, j - 1);
		}
	}

	printf("%.8f", tsp(1, 1));

	return 0;
}

double getDist(int point1, int point2) {
	return sqrt(pow(vec[point1].first - vec[point2].first, 2)
		+ pow(vec[point1].second - vec[point2].second, 2));
}

double tsp(int node, int visited) {
	if (visited == ((1 << nodeNum) - 1)) {
		if (cost[node][1] != 0) {
			return cost[node][1];
		}
	}

	if (dp[node][visited] != 0) {
		return dp[node][visited];
	}

	dp[node][visited] = MAX_COST;

	for (int i = 1; i <= nodeNum; i++) {
		if (!(visited & (1 << (i - 1))) && cost[node][i] != 0) {
			double tspVal = tsp(i, visited | (1 << (i - 1)));
			dp[node][visited] = min(dp[node][visited], cost[node][i] + tspVal);
		}
	}

	return dp[node][visited];
}