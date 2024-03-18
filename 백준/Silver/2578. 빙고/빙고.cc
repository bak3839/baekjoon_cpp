#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

vector<int> row(5, 0);
vector<int> col(5, 0);
vector<pii> loc(26);

void Solution() {
    int n, cnt = 1, res = 0, ans = 0, r, c, x1 = 0, x2 = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> n;

            if (ans != 0) continue;

            r = loc[n].first;
            c = loc[n].second;

            row[r]++;
            col[c]++;

            if (r == c) x1++;
            if ((r == 0 && c == 4) || (r == 1 && c == 3) || (r == 2 && c == 2) || (r == 3 && c == 1) || (r == 4 && c == 0)) x2++;

            if (x1 == 5) {
                res++;
                x1 = 0;
            }
            if (x2 == 5) {
                res++;
                x2 = 0;
            }
            if (row[r] == 5) res++;
            if (col[c] == 5) res++;
            
            if (res >= 3) ans = cnt;

            cnt++;
        }
    }

    cout << ans;
}

void Input() {
    int n;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> n;
            loc[n] = { i, j };
        }
    }   
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
