#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int getRoot(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = getRoot(parent[x]);
}

void Union(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);

    if (a == b) return;

    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool search(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);

    if (a == b) return true;
    else return false;
}

void input(int n, int m) {
    int a, b, t;

    parent.resize(n + 1);
    for (int i = 1;i <= n;i++) parent[i] = i;

    for (int i = 0;i < m;i++) {
        cin >> t >> a >> b;

        if (t) {
            a = getRoot(a);
            b = getRoot(b);
            if (a == b) cout << "YES\n";
            else cout << "NO\n";
        }
        else Union(a, b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    input(n, m);
    return 0;
}