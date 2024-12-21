#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<char> doll;

void Solution() {
    int L = 0, R = 0, ans = 1000001, cnt = 0;

    while (R < N) {
        if (cnt < K) {
            if (doll[R] == '1') cnt++;
            R++;
        }
        else {
            if (doll[L] == '1') cnt--;
            ans = min(ans, R - L);
            L++;
        }
    }

    while (cnt == K && L < R) {
        if (doll[L] == '1') cnt--;
        ans = min(ans, R - L);
        L++;
    }

    if (ans == 1000001) cout << -1;
    else cout << ans;
}

void Input() {
    cin >> N >> K;

    doll.resize(N);

    for (int i = 0; i < N; i++)
        cin >> doll[i];
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