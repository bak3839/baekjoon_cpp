#include <iostream>
#include <vector>

using namespace std;

int N, cnt, res;
vector<int> graph;
vector<bool> visit;

void dfs(int x) {
    cnt++;
    
    if (visit[graph[x]] || graph[x] == -1) return;

    visit[x] = true;
    dfs(graph[x]);
    visit[x] = false;
}

void Solution() {
    int ans = 0;

    for (int i = 1; i <= N; i++) {
        cnt = 0;
        dfs(i);

        if (res < cnt) {
            res = cnt;
            ans = i;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N;

    graph.resize(N + 1, -1);
    visit.resize(N + 1, false);

    for (int i = 1; i <= N; i++) 
        cin >> graph[i];
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
