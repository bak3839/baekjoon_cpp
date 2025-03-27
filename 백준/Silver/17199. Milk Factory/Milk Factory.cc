#include <bits/stdc++.h>

using namespace std;

int a, b, N, ans = -1;
vector<int> graph[101];

int dfs(int x) {
    int cnt = 1;

    for (int i = 0; i < graph[x].size(); i++) {
        cnt += dfs(graph[x][i]);
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        if (dfs(i) == N) {
            ans = i;
            break;
        }
    }

    cout << ans;
    return 0;
}