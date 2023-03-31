#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cnt = 1;
vector<int> parent;

int getRoot(int x) {
    if (parent[x] == x) return x;
    else return getRoot(parent[x]);
}

void Union(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);

    if (a == b) return;

    if (a < b) parent[b] = a;
    else parent[a] = b;
}

void solve() {
    int n, a, b;
    cin >> n;

    cout << "Scenario " << cnt++ << ":\n";
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        a = getRoot(a); b = getRoot(b);
        if (a == b) cout << "1\n";
        else cout << "0\n";
    }
    cout << "\n";
}

void input() {
    int n, k, a, b;
    cin >> n >> k;
    parent.resize(n);

    for (int i = 0; i < n; i++) parent[i] = i;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        Union(a, b);
    }    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        input();
        solve();
    }
    return 0;
}