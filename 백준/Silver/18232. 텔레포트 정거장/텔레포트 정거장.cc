#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N, M, S, E;
vector<int> visit;
vector<vector<int>> teleport;

void Solution() {
    int ans = 0;

    queue<pii> q;
    q.push({ S, 0 });
    visit[S] = true;

    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (now == E) {
            ans = cnt;
            break;
        }

        if (now - 1 > 0 && !visit[now - 1]) {
            visit[now - 1] = true;
            q.push({ now - 1, cnt + 1 });
        }

        if (now + 1 <= N && !visit[now + 1]) {
            visit[now + 1] = true;
            q.push({ now + 1, cnt + 1 });
        }

        for (int i = 0; i < teleport[now].size(); i++) {
            int next = teleport[now][i];

            if (visit[next]) continue;

            visit[next] = true;
            q.push({ next, cnt + 1 });
        }
    }

    cout << ans;
}

void Input() {
    int s, e;
    cin >> N >> M >> S >> E;

    teleport.resize(N + 1);
    visit.resize(N + 1, false);
    
    for (int i = 0; i < M; i++) {
        cin >> s >> e;
        teleport[s].push_back(e);
        teleport[e].push_back(s);
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