#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int S, T;

void Solution() {
    queue<pii> q;
    q.push({ S, T });

    int cnt = 0;

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            int s = q.front().first;
            int t = q.front().second;
            q.pop();

            if (s == t) {
                cout << cnt << "\n";
                return;
            }

            if (s + s <= t + 3) {
                q.push({ s + s, t + 3 });
            }
            
            if (s + 1 <= t) {
                q.push({ s + 1, t });
            }
        }

        cnt++;
    }
}

void Input() {
    cin >> S >> T;
}

void Solve() {
    int C;
    cin >> C;

    while (C--) {
        Input();
        Solution();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}