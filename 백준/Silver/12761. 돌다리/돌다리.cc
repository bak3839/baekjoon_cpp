#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int A, B, N, M;
vector<bool> visit;

void Solution() {
    queue<int> q;
    q.push(N);
    visit[N] = true;

    int mv[8] = { 1, -1, A, B, -1 * A, -1 * B, A, B };
    int ans = 0;

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            int now = q.front();
            q.pop();

            if (now == M) {
                cout << ans;
                return;
            }

            for (int i = 0; i < 8; i++) {
                int next;

                if (i > 5) next = now * mv[i];
                else next = now + mv[i];

                if (next < 0 || next > 100000 || visit[next]) continue;

                q.push(next);
                visit[next] = true;
            }
        }
        ans++;
    }
}

void Input() {
    cin >> A >> B >> N >> M;

    visit.resize(100001, false);
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