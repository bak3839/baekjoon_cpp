#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int N, M;
vector<pii> v;
vector<int> parent;

int GetRoot(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = GetRoot(parent[x]);
}

void Union(int a, int b) {
    if (a > b) {
        int tmp = b;
        b = a;
        a = tmp;
    }

    parent[b] = a;
}

void Solution() {
    if (N - 1 != M) {
        cout << "graph\n";
        return;
    } 

    int a, b;

    parent.resize(N + 1);

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (pii p : v) {
        a = GetRoot(p.first);
        b = GetRoot(p.second);

        if (a == b) {
            cout << "graph\n";
            return;
        }

        Union(a, b);
    }

    cout << "tree\n";
}

void Input() {
    int a, b;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v.push_back({ a, b });
    }
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
        v.clear();
        parent.clear();
    }  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}