#include <iostream>
#include <vector>

using namespace std;

int ans;
vector<int> parent;

int getRoot(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = getRoot(parent[x]);
}

void Union(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);

    if (a == b) {
        ans++;
        return;
    }

    if (a < b) parent[b] = a;
    else parent[a] = b;
}

void Solution(int N) {
    for (int i = 2; i <= N; i++) {
        if (getRoot(i) != 1) {
            ans++;
            parent[i] = 1;
        }
    }
    cout << ans;
}

void Input(int N, int M) {
    int u, v;
    parent.resize(N + 1);

    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        Union(u, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    Input(N, M);
    Solution(N);
    return 0;
}