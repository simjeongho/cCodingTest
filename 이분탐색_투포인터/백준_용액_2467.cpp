#pragma warning (disable : 4996)

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;

int N;
vector<int> pl;
vector<int> mi;
int mcnt, pcnt;
int mis = INF;
int pis = INF;
int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int t;
		scanf("%d", &t);
		if (t < 0) {
			mi.push_back(t);
			mcnt++;
		}
		else {
			pl.push_back(t);
			pcnt++;
		}
	}
	int temp = INF;
	int ans1 = 0; int ans2 = 0;
	for (int i = 0; i < pcnt; i++) {
		int tmp = 0; int a1 = 0; int a2 = 0; int tresult = 0;
		if (mcnt < 2) break;
		tmp = lower_bound(mi.begin(), mi.end(), -pl[i]) - mi.begin();
		if (tmp == 0) {
			//만약 제일 작다면 
			a1 = pl[i];
			a2 = mi[tmp];
			tresult = abs(pl[i] + mi[tmp]);
		}
		else if (tmp == mcnt) {
			// 만약 제일 크다면 
			a1 = pl[i];
			a2 = mi[tmp -1];
			tresult = abs(pl[i] + mi[tmp - 1]);
		}
		else {
			if (abs(pl[i] + mi[tmp]) > abs(pl[i] + mi[tmp - 1])) {
				a1 = pl[i];
				a2 = mi[tmp - 1];
				tresult = abs(pl[i] + mi[tmp - 1]);
			}
			else {
				a1 = pl[i];
				a2 = mi[tmp];
				tresult = abs(pl[i] + mi[tmp]);
			}
		}
		if (temp > tresult) {
			ans1 = a1; ans2 = a2; temp = tresult;
		}
	}
	if (mcnt >= 2) {
		mis = abs(mi[mcnt - 1] + mi[mcnt - 2]);
		if (mis < temp) {
			ans1 = mi[mcnt - 2];
			ans2 = mi[mcnt - 1];
			temp = mis;
		}
	}
	if (pcnt >= 2) {
		pis = abs(pl[0] + pl[1]);
		if (pis < temp) {
			ans1 = pl[0];
			ans2 = pl[1];
			temp = pis;
		}
	}
	if (ans1 > ans2) swap(ans1, ans2);
	printf("%d %d\n", ans1, ans2);

	return 0;
}