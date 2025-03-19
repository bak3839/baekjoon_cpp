#include <bits/stdc++.h>

using namespace std;

int N, p[11], color[11], visited[11];
vector<int> graph[11];

int dfs(int x, int c) {
    int cnt = 1;
    visited[x] = 1;

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];

        if (visited[next] || color[next] != c) continue;

        cnt += dfs(next, c);
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, ans = INT_MAX, temp;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> p[i];

    for (int i = 1; i <= N; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> temp;
            graph[i].push_back(temp);
            graph[temp].push_back(i);
        }   
    }

    // 비트마스킹을 사용하여 구역을 나누는 모든 경우의 수
    for (int i = 1; i < (1 << N) - 1; i++) {
        int idx1 = 0, idx2 = 0, sum1 = 0, sum2 = 0, res1, res2;

        for (int j = 1; j <= N; j++) {
            if (i & (1 << j)) {
                color[j] = 1;
                idx1 = j;
                sum1 += p[j];
            }
            else {
                idx2 = j;
                sum2 += p[j];
            }
        }

        res1 = dfs(idx1, 1);
        res2 = dfs(idx2, 0);

        if (res1 + res2 == N) ans = min(ans, abs(sum1 - sum2));

        memset(color, 0, sizeof(color));
        memset(visited, 0, sizeof(visited));
    }

    if (ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}
