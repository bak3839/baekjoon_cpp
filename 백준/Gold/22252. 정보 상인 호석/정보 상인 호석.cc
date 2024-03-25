#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
using pqi = priority_queue<int>;
int Q;

void Solution() {
    long long ans = 0;
    int n, C, b, k;
    string name;

    map<string, pqi> m;

    while (Q--) {
        cin >> n >> name;

        if (n == 1) {
            cin >> k;

            for (int i = 0; i < k; i++) {
                cin >> C;
                m[name].push(C);
            }
        }

        else {
            cin >> b;

            if (m.find(name) == m.end()) continue;

            pqi pq = m[name];

            while (!pq.empty() && b--) {
                ans += pq.top();
                pq.pop();
            }

            m[name] = pq;
        }
    }

    cout << ans;
}

void Input() {
    cin >> Q;
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