#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int getRoot(int x) {
    if (x == parent[x]) return x;
    return parent[x] = getRoot(parent[x]);
}

void Union(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);

    if (a == b) return;

    if (a > b) parent[b] = a;
    else parent[a] = b;
}

void Solution(int N) {
    int prev, now, ans = 0;
    for (int i = 0;i < N;i++) {
        if (i == 0) {
            cin >> prev;
            continue;
        }

        cin >> now;
        if (getRoot(prev) != getRoot(now)) ans++;
        prev = now;
    }
    cout << ans;
}

void Input(int N, int M) {
    int a, b;
    parent.resize(N + 1);
    for (int i = 1;i <= N;i++)
        parent[i] = i;

    for (int i = 0;i < M;i++) {
        cin >> a >> b;
        Union(a, b);
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