#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N, M, P;
vector<bool> visit;
vector<int> change;

void Solution() {
    int c = P, cnt = 0;
    visit[P] = true;

    if (change[P] == 0) {
        cout << 0;
        return;
    }

    while (1) {
        int next = change[c];

        if (change[next] == 0) break;

        if (visit[next]) {
            cnt = -2;
            break;
        }

        cnt++;
        c = next;
        visit[next] = true;
    }

    cout << cnt + 1;
}

void Input() {
    int a, b;
    cin >> N >> M >> P;

    visit.resize(M + 1, false);
    change.resize(M + 1, 0);

    for (int i = 0; i < N; i++) {
        cin >> a >> b;

        if (change[b] != 0) continue;

        change[b] = a;
    }
}

void Solve() {
    Input();
    Solution();
}

int main() {
    Solve();
    return 0;
}