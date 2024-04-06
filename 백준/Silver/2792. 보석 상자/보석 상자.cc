#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> jewel;

void Solution() {
    int L = 1, R = 1000000000, mid, ans = 1000000000, cnt;

    while (L <= R) {
        cnt = 0;
        mid = (L + R) / 2;

        for (int i = 0; i < M; i++) {
            cnt += jewel[i] / mid;
            if (jewel[i] % mid != 0) cnt++;
        }

        if (cnt > N) {
            L = mid + 1;
        }
        else {
            R = mid - 1;
            ans = min(ans, mid);
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;

    jewel.resize(M);

    for (int i = 0; i < M; i++)
        cin >> jewel[i];
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