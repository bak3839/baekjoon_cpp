#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> parent;

int getRoot(int x) {
    if (parent[x] == x) return x;
    else return getRoot(parent[x]);
}

void Union(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);

    if (a == b) return;

    if (a > b) parent[a] = b;
    else parent[b] = a;
}

void input(int N) {
    int x, y;
    parent.resize(N + 1);

    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 0; i < N - 2; i++) {
        cin >> x >> y;
        Union(x, y);
    }
}

void solve(int N) {
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (getRoot(i) == i) ans.push_back(i);
    }

    for (int i = 0; i < 2; i++) cout << ans[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    input(N);
    solve(N);
    return 0;
}