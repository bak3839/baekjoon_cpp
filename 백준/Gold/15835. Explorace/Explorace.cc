#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int v1;
    int v2;
    int cost;
}Edge;

int N, M, cnt = 1;
vector<int> parent;
vector<Edge> edges;

bool compare(Edge e1, Edge e2) {
    return e1.cost < e2.cost;
}

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
    int a, b, ans = 0;

    for (Edge e : edges) {
        a = GetRoot(e.v1);
        b = GetRoot(e.v2);

        if (a != b) {
            Union(a, b);
            ans += e.cost;
        }
    }

    cout << "Case #" << cnt++ << ": " << ans << " meters\n";
}

void Input() {
    cin >> N >> M;

    edges.resize(M);
    parent.resize(N + 1);

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 0; i < M; i++) 
        cin >> edges[i].v1 >> edges[i].v2 >> edges[i].cost;

    sort(edges.begin(), edges.end(), compare);
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
        edges.clear();
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