#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int a, b, N , M;
vector<bool> visit;
vector<vector<int>> graph;

int bfs() {
    if (a == b) return 0;

    queue<int> q;
    q.push(a);
    visit[a] = true;

    int ans = 0;
    bool pass = false;

    while (!q.empty()) {
        int size = q.size();
        ans++;

        for (int i = 0; i < size; i++) {
            int n = q.front();
            q.pop();

            for (int j = 0; j < graph[n].size(); j++) {
                int next = graph[n][j];

                if (visit[next]) continue;

                q.push(next);
                visit[next] = true;

                if (next == b) {
                    pass = true;
                    break;
                }
            }
        }

        if (pass) break;
    }

    if (visit[b]) return ans;
    return -1;
}

void Solution() {
    cout << bfs();
}

void Input() {
    int v1, v2;
    cin >> a >> b >> N >> M;

    graph.resize(N + 1);
    visit.resize(N + 1, false);

    for (int i = 0; i < M; i++) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
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
