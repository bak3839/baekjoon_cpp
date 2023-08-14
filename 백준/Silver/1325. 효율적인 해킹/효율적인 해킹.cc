#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, cnt;
vector<int> ans;
vector<int> sum;
vector<bool> visit;
vector<vector<int>> graph;

void dfs(int x) {
    visit[x] = true;

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (visit[next]) continue;

        dfs(next);
        cnt++;
    }
}

void Solution() {
    int max_res = 0;

    for (int i = 1; i <= N; i++) {
        cnt = 1;
        dfs(i);
        sum[i] = cnt;
        fill(visit.begin(), visit.end(), false);

        if (sum[i] > max_res) {
            ans.clear();
            ans.push_back(i);
            max_res = sum[i];
        }

        else if (sum[i] == max_res)
            ans.push_back(i);
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

void Input() {
    cin >> N >> M;

    graph.resize(N + 1);
    sum.resize(N + 1, -1);
    visit.resize(N + 1, false);

    int a, b;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[b].push_back(a);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}