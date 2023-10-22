#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<char> color;
vector<vector<int>> graph;

bool bfs(int x) {
    queue<int> q;
    q.push(x);

    color[x] = 'R';

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];

            if (color[next] == color[now]) return false;
            if (color[next] != 'N') continue;

            color[next] = color[now] == 'R' ? 'B' : 'R';
            q.push(next);
        }
    }
    return true;
}

void Solution() {
    for (int i = 1; i <= N; i++) {
        if (color[i] != 'N') continue;

        if (!bfs(i)) {
            cout << "impossible\n";
            return;
        }
    }
    cout << "possible\n";
}

void Input() {
    int v1, v2;
    cin >> N >> M;

    graph.resize(N + 1);
    color.resize(N + 1, 'N');   

    for (int i = 0; i < M; i++) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
        color.clear();
        graph.clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
