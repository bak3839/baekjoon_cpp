#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<bool> visit(26, false);
vector<vector<int>> graph(26);

bool BFS(int start, int end) {
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        for (int i = 0; i < graph[n].size(); i++) {
            int next = graph[n][i];

            if (visit[next]) continue;

            if (next == end) return true;

            q.push(next);
            visit[next] = true;
        }
    }

    return false;
}

void Solution() {
    char v1, v2;
    string is;
    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> v1 >> is >> v2;

        if (BFS(v1 - 'a', v2 - 'a')) cout << "T\n";
        else cout << "F\n";

        fill(visit.begin(), visit.end(), false);
    }
}

void Input() {
    char v1, v2;
    string is;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> v1 >> is >> v2;

        graph[v1 - 'a'].push_back(v2 - 'a');
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
    return 0;
}