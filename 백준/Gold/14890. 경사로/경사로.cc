#include <bits/stdc++.h>

using namespace std;

int N, L;
vector<vector<int>> A;

bool Row(int r) {
    int now, next;
    vector<bool> checked(N, false);

    for (int c = 0; c < N - 1; c++) {
        now = A[r][c];
        next = A[r][c + 1];

        if (abs(now - next) > 1) return false;

        if (now > next) {
            if (c + L >= N) return false;

            for (int j = c + 1; j <= c + L; j++) {
                if (!checked[j] && next == A[r][j]) {
                    checked[j] = true;
                    continue;
                }

                return false;
            }

            c = c + L - 1;
        }

        else if (now < next) {
            if (c + 1 < L) return false;

            for (int j = c; j >= c - L + 1; j--) {
                if (!checked[j] && now == A[r][j]) {
                    checked[j] = true;
                    continue;
                }

                return false;
            }
        }
    }

    return true;
}

bool Col(int c) {
    int now, next;
    vector<bool> checked(N, false);

    for (int r = 0; r < N - 1; r++) {
        now = A[r][c];
        next = A[r + 1][c];

        if (abs(now - next) > 1) return false;

        if (now > next) {
            if (r + L >= N) return false;

            for (int j = r + 1; j <= r + L; j++) {
                if (!checked[j] && next == A[j][c]) {
                    checked[j] = true;
                    continue;
                }

                return false;
            }

            r = r + L - 1;
        }

        else if (now < next) {
            if (r + 1 < L) return false;

            for (int j = r; j >= r - L + 1; j--) {
                if (!checked[j] && now == A[j][c]) {
                    checked[j] = true;
                    continue;
                }

                return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
    cin >> N >> L;
    A.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        if(Row(i)) ans++;
        if(Col(i)) ans++;
    }

    cout << ans;
    return 0;
}