#include <iostream>
#include <vector>

using namespace std;

int N, M, J;
vector<int> loc;

void Solution() {
    int L = 1, R = M, ans = 0;

    for (int i = 0; i < J; i++) {
        int now = loc[i];

        if (now < L) {
            ans += L - now;
            L = now;
            R = L + (M - 1);
        }

        else if (now > R) {
            ans += now - R;
            R = now;
            L = R - (M - 1);
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M >> J;

    loc.resize(J);

    for (int i = 0; i < J; i++)
        cin >> loc[i];
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
