#pragma warning (disable : 4996)
/*
	문제를 생각해보면 다음과 같다. 
	0번째 : 0만가능
	1번째 : 0 1 가능
	2번째 : 0 1 2 가능 
	k번째 : 0 1 2 ... k 가능 

	-1인 경우는 도둑이 훔쳐간 상태이다. 
	-1인 경우에 도둑은 한 번에 하나만 가져간다는 말은 없으며 그냥 열을 통째로 가져간듯 하다.
	제단의 높이가 정해지는 경우는 세 가지가 존재한다. 
	1. 이전 제단의 높이보다 낮을 경우
	2. 이전 제단의 높이와 같을 경우
	3. 이전 제단의 높이보다 높을 경우

	10000 * 4byte = 40000 byte = 40KByte * 10000 = 400,000KByte = 400MB
	메모리 초과가 나게 된다. 따라서 높이에 해당하는 DP배열의 사이즈를 줄여줘야한다. 

	메모리 제한이 256MB이므로 10000 * 4byte = 40KB * 5000 = 200MB //메모리 제한 만족한다. 
	c++에서는 pageFault문제 때문에 열로 메모리를 탐색하는 것이 효율이 좋다. 따라서 높이에 해당하는 부분을 높이로 만들어준다. 
*/
#include <cstdio>
#include <algorithm>
#define MAX 10000+2
#define MOD 1000000007
using namespace std;
int N; // 제단의 열의 수
int inputs[MAX];
int dp[MAX][5001]; // 제단 열 높이 
int ans;
void makeDP() {
	//초기 값 설정
	dp[0][0] = 1; // 맨 왼쪽 높이 0은 1로 초기화한다. 
	for (int i = 1; i < N; i++) {
		if (inputs[i] == -1) {
			//만약 도둑맞은 제단이었다면 다음과 같이 가능한 높이까지 모두 채워준다.
			for (int j = 0; j <= min(i, N - i - 1); j++) {
				//i를 열로 생각해야한다.
				if (j == 0) {
					dp[i][j] += dp[i - 1][j];
					dp[i][j] %= MOD;
					dp[i][j] += dp[i - 1][j + 1];
					dp[i][j] %= MOD;
				}
				else {
					 // 아니라면 세 가지 경우를 모두 생각해주어야 한다.
					dp[i][j] += dp[i - 1][j];
					dp[i][j] %= MOD;
					dp[i][j] += dp[i - 1][j + 1];
					dp[i][j] %= MOD;
					dp[i][j] += dp[i - 1][j - 1];
					dp[i][j] %= MOD;
				}
			}
		}
		//만약 입력받은 높이가 -1이 아니었다면 
		else {
			//해당하는 열, 높이 위치의 배열 칸에다가 값을 넣어줘야한다.
			if (inputs[i] == 0) {
				dp[i][inputs[i]] += dp[i - 1][inputs[i]];
				dp[i][inputs[i]] %= MOD;
				dp[i][inputs[i]] += dp[i - 1][inputs[i] + 1];
				dp[i][inputs[i]] %= MOD;
			}
			else {
				dp[i][inputs[i]] += dp[i - 1][inputs[i]];
				dp[i][inputs[i]] %= MOD;
				dp[i][inputs[i]] += dp[i - 1][inputs[i] + 1];
				dp[i][inputs[i]] %= MOD;
				dp[i][inputs[i]] += dp[i - 1][inputs[i] - 1];
				dp[i][inputs[i]] %= MOD;
			}
		}
	}
	ans = dp[N - 1][0] % MOD;
}

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &inputs[i]); // 인풋 입력
		//만약 입력받은 높이가 min(i, N - i - 1)보다 크다면 바로 0을 리턴한다.
		if (inputs[i] > min(i, N - i - 1)) {
			printf("%d\n", 0);
			return 0;
		}
	}
	makeDP();
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j <= min(i, N - 1 - i); j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}*/
	printf("%d\n", ans);
	return 0;
}