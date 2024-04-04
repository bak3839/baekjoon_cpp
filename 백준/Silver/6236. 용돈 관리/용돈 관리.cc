#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> pay;

void Solution() {
    bool pass;
    int L = 1, R = 1000000000, mid, cnt, ans = 1000000001, now;

    while (L <= R) {
        cnt = 1;
        mid = (L + R) / 2;
        now = mid;
        pass = true;

        for (int i = 0; i < N; i++) {
            if (mid < pay[i]) {
                L = mid + 1;
                pass = false;
                break;
            }

            if (now < pay[i]) {
                now = mid;
                cnt++;
            }

            now -= pay[i];
        }

        if (!pass) continue;

        if (cnt <= M) {
            R = mid - 1;
            ans = min(ans, mid);
        }
        else {
            L = mid + 1;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;

    pay.resize(N);

    for (int i = 0; i < N; i++)
        cin >> pay[i];
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