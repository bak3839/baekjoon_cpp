#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> ans;
vector<vector<int>> tree;

void dfs(int x, int depth) {
    ans[x] = depth;

    for (int i = 0; i < tree[x].size(); i++) {
        int next = tree[x][i];

        if (ans[next] != -1) continue;

        dfs(next, depth + 1);
    }
}

void Solution() {
    dfs(S, 0);

    for (int i = 1; i <= N; i++)
        cout << ans[i] << "\n";
}

void Input() {
    int parent;
    cin >> N;

    ans.resize(N + 1, -1);
    tree.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> parent;

        if (parent == -1) {
            S = i;
            ans[i] = 0;
            continue;
        }

        tree[parent].push_back(i);
    }
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}