#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
using pii = pair<int, int>;

int N, M, Len;
vector<int> X;
vector<pii> animals;

void Solution() {
    int size = animals.size(), ans = 0;

    for (int i = 0; i < size; i++) {
        int L = 0, R = M - 1, mid, x = animals[i].first, y = animals[i].second;

        while (L <= R) {
            mid = L + (R - L) / 2;

            if (abs(X[mid] - x) + y <= Len) {
                ans++;
                break;
            }
            else {
                if (x >= X[mid]) 
                    L = mid + 1;

                else 
                    R = mid - 1;
            }
        }
    }

    cout << ans;
}

void Input() {
    int x, y;
    cin >> M >> N >> Len;

    for (int i = 0; i < M; i++) {
        cin >> x;
        X.push_back(x);
    }
    sort(X.begin(), X.end());

    for (int i = 0; i < N; i++) {
        cin >> x >> y;

        if (y > Len) continue;
        animals.push_back({ x, y });
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