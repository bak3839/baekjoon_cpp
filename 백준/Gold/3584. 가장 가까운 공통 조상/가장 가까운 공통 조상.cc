#include <iostream>
#include <vector>

using namespace std;

int N;
vector<bool> visit;
vector<vector<int>> graph;

int Search(int v) {
    int now, ans = -1;

    for (int i = 0; i < graph[v].size(); i++) {
        now = graph[v][i];

        if (ans != -1) break;

        if (visit[now]) {
            ans = now;
            break;
        }

        visit[now] = true;
        ans = Search(now);
    }

    return ans;
}

void Solution() {
    int v1, v2, now, ans = -1;
    cin >> v1 >> v2;
    visit[v1] = true;
    visit[v2] = true;

    ans = Search(v1);
    if(ans == -1) ans = Search(v2);

    cout << ans << "\n";

    graph.clear();
    visit.clear();
}

void Input() {
    int parent, child;
    cin >> N;

    graph.resize(N + 1);
    visit.resize(N + 1, false);

    for (int i = 0; i < N - 1; i++) {
        cin >> parent >> child;
        graph[child].push_back(parent);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
    }

    return 0;
}