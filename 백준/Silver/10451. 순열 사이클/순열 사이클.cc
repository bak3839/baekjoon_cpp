#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> connect;
vector<bool> visit;

void dfs(int x) {
    visit[x] = true;

    int next = connect[x];

    if (visit[next]) return;

    dfs(next);
}

void Solution() {
    int ans = 0;

    for (int i = 1; i <= N; i++) {
        if (visit[i]) continue;

        dfs(i);
        ans++;
    }

    cout << ans << "\n";
}

void Input() {
    cin >> N;

    connect.resize(N + 1);
    visit.resize(N + 1, false);

    for (int i = 1; i <= N; i++) 
        cin >> connect[i];
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
        visit.clear();
        connect.clear();        
    }
}

int main() {
    Solve();
    return 0;
}