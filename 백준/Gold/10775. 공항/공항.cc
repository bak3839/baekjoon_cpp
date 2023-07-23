#include <iostream>
#include <vector>

using namespace std;

int G, P;
vector<int> parent;
vector<int> g;

int getRoot(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = getRoot(parent[x]);
}

void Solution() {
    int ans = 0, gate;

    for (int i = 0; i < P; i++) {
        gate = getRoot(g[i]);
        
        if (gate == 0) break;

        parent[gate] = gate - 1;
        ans++;
    }

    cout << ans;
}

void Input() {
    cin >> G >> P;

    g.resize(P);
    parent.resize(G + 1);

    for (int i = 0; i < P; i++)
        cin >> g[i];

    for (int i = 0; i <= G; i++)
        parent[i] = i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}