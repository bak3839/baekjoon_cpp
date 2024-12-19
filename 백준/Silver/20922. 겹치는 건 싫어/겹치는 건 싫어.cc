#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, K;
vector<int> num, counts;

void Solution() {
    int L = -1, R = 0, ans = 0, next;

    while (L < R && R < N) {
        next = num[R];

        if (counts[next] < K) {
            counts[next]++;
            ans = max(ans, R - L);
            R++;          
        }
        else {
            L++;
            counts[num[L]]--;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> K;

    num.resize(N);
    counts.resize(100001, 0);

    for (int i = 0; i < N; i++)
        cin >> num[i];
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}