#include <iostream>
#include <vector>

using namespace std;

int d, ans;
vector<vector<int>> tree;
vector<bool> visit;

void dfs(int node) {
    bool flag = false;
    visit[node] = true;   

    for (int i = 0; i < tree[node].size(); i++) {
        int v = tree[node][i];
        if (!visit[v]) {
            dfs(v);
            flag = true;
        }
    }

    if (!flag) ans++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, root = 0, n;
    cin >> N;
    tree.resize(N);
    visit.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> n;
        if (n == -1) root = i;
        else tree[n].push_back(i);
    }
    cin >> d;
    if (d == root) cout << 0;
    else {
        dfs(d);
        ans = 0;
        dfs(root);

        cout << ans;
    }
    return 0;
}