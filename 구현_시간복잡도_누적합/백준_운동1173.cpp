#include <iostream>
using namespace std;
int N, m, M, T, R;
int cnt, currentPulse, time;
int main() {
    cin >> N >> m >> M >> T >> R;
    currentPulse = m;
    if (currentPulse + T > M) {
        cout << -1 << '\n';
        return 0;
    }
    for (int cnt = 0; cnt < N;) {
        time++;
        if (currentPulse + T <= M) {
            currentPulse += T;
            cnt++;
        }
        else {
            currentPulse -= R;
            if (currentPulse < m) currentPulse = m;
        }
    }
    cout << time << '\n';
}