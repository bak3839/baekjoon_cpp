#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int N, M, S, E;
vector<bool> visit;
vector<vector<pii>> graph;

void Solution() {
    bool pass;
    int L = 1, R = 1000000000, mid, ans = 0;

    while (L <= R) {
        pass = false;
        mid = (L + R) / 2;

        queue<int> q;
        q.push(S);
        visit[S] = true;

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            if (x == E) {
                pass = true;
                break;
            }

            for (int i = 0; i < graph[x].size(); i++) {
                int next = graph[x][i].first;
                int wegiht = graph[x][i].second;

                if (wegiht < mid || visit[next]) continue;

                q.push(next);
                visit[next] = true;
            }
        }

        if (pass) {
            ans = max(ans, mid);
            L = mid + 1;
        }
        else {
            R = mid - 1;
        }

        fill(visit.begin(), visit.end(), false);
    }

    cout << ans;
}

void Input() {
    int A, B, C;
    cin >> N >> M;

    graph.resize(N + 1);
    visit.resize(N + 1, false);

    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;

        graph[A].push_back({ B, C });
        graph[B].push_back({ A, C });
    }
    cin >> S >> E;
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