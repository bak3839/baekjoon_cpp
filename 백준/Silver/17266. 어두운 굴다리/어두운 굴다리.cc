#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> X;

void Solution() {
    bool pass;
    int L = 1, R = N, mid, ans = 0, prev;

    while (L <= R) {
        prev = 0;
        pass = true;
        mid = (L + R) / 2;

        for (int i = 0; i < M; i++) {
            int end = X[i + 1] - mid;
            if (i == M - 1) end += mid;

            if (X[i] - mid > prev ||  X[i] + mid < end) {
                pass = false;
                break;
            }
            prev = X[i] + mid;
        }

        if (pass) {
            R = mid - 1;
            ans = mid;
        }
        else {
            L = mid + 1;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;

    X.resize(M + 1);

    for (int i = 0; i < M; i++)
        cin >> X[i];
    X[M] = N;
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