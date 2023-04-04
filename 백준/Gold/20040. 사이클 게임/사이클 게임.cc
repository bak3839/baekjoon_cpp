#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ans;
bool pass;
vector<int> parent;

int getRoot(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = getRoot(parent[x]);
}

bool Union(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);

    if (a == b) return true;

    if (a < b) parent[b] = a;
    else parent[a] = b;

    return false;
}

void input(int n, int m) {
    parent.resize(n);

    for (int i = 0; i < n; i++) parent[i] = i;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (pass) continue;

        pass = Union(a, b);
        if(pass) ans = i + 1;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    input(n, m);
    return 0;
}