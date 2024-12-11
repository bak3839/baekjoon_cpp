#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using pii = pair<int, int>;

inline int move(int n) {
    return (n == 0 ? 1 : 0);
}

int N;
vector<int> loc;
vector<stack<int>> rod(2);

void Solution() {
    int ans = 0, target = N, now, next, num;
    vector<pii> res;

    while (target > 0) {
        now = loc[target];

        while (rod[now].top() != target) {
            num = rod[now].top();
            next = move(now);

            res.push_back({ now + 1, next + 1 });
            loc[num] = next;

            rod[next].push(num);
            rod[now].pop();
            ans++;
        }

        res.push_back({ now + 1, 3 });
        rod[now].pop();
        target--;
    }

    cout << ans + N << "\n";

    for (auto r : res)
        cout << r.first << " " << r.second << "\n";
}

void Input() {
    int num;
    cin >> N;

    loc.resize(N + 1, 0);

    for (int i = 0; i < N; i++) {
        cin >> num;
        rod[0].push(num);
    }
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