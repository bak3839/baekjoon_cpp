#include <iostream>
#include <vector>

using namespace std;

int N, M, Q;
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
    int a, b;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        
        a = GetRoot(a);
        b = GetRoot(b);

        Union(a, b);
    }

    for (int i = 0; i < Q; i++) {
        cin >> a >> b;

        a = GetRoot(a);
        b = GetRoot(b);

        if (a != b) cout << "N\n";
        else cout << "Y\n";
    }
}

void Input() {
    cin >> N >> M >> Q;

    parent.resize(N + 1);

    for (int i = 1; i <= N; i++)
        parent[i] = i;   
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}