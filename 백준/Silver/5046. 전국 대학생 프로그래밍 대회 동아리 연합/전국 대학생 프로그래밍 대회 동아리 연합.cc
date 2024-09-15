#include <iostream>
#include <vector>

using namespace std;

int N, B, H, W;

void Solution() {
    int p, a, ans = 2100000000;

    for (int i = 0; i < H; i++) {
        cin >> p;

        for (int j = 0; j < W; j++) {
            cin >> a;

            if (a < N || N * p > B) continue;

            ans = min(ans, N * p);
        }
    }

    if (ans == 2100000000) cout << "stay home";
    else cout << ans;
}

void Input() {
    cin >> N >> B >> H >> W;
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