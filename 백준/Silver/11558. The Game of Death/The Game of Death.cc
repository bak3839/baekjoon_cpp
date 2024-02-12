#include <iostream>
#include <vector>

using namespace std;

int N, ans;
vector<int> A;
vector<bool> visit;

void dfs(int x, int cnt) {
    if (visit[x]) return;

    if (x == N - 1) {
        ans = cnt;
        return;
    }

    visit[x] = true;
    dfs(A[x] - 1, cnt + 1);  
}

void Solution() {
    dfs(0, 0);
    cout << ans << "\n";

    ans = 0;
    A.clear();
    visit.clear();
}

void Input() {
    cin >> N;

    A.resize(N);
    visit.resize(N, false);

    for (int i = 0; i < N; i++)
        cin >> A[i];
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();    
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
