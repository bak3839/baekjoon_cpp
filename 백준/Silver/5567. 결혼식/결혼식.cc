#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<bool> check;
vector<int> Friend;
vector<vector<int>> graph;

void Solution() {
    int ans = 0, node;

    check[1] = true;
    for (int i = 0; i < graph[1].size(); i++) {
        node = graph[1][i];

        ans++;
        check[node] = true;
        Friend.push_back(node);
    }

    for (int i = 0; i < Friend.size(); i++) {
        node = Friend[i];

        for (int j = 0; j < graph[node].size(); j++) {
            int now = graph[node][j];

            if (check[now]) continue;

            ans++;
            check[now] = true;
        }
    }
    cout << ans;
}

void Input() {
    cin >> n >> m;

    graph.resize(n + 1);
    check.resize(n + 1, false);

    int s, e;

    for (int i = 0; i < m; i++) {
        cin >> s >> e;

        graph[s].push_back(e);
        graph[e].push_back(s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();

    return 0;
}