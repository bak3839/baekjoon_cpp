#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int v1;
    int v2;
    int cost;
}Edge;

vector<Edge> road;
int parent[1001];
int res, cnt;

int getRoot(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
}

void uni(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool find(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);
    if (a == b) return true;
    else return false;
}

void kruskal(Edge e) {
    if (!find(e.v1, e.v2)) {
        uni(e.v1, e.v2);
        if (!e.cost) ++res;
        --cnt;
    }
}

bool cmp(Edge e1, Edge e2) {
    if (e1.cost < e2.cost) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Edge e;
    int N, M, ans = 0, ent;
    cin >> N >> M;
    cnt = N - 1;

    for (int i = 0;i <= N;i++) parent[i] = i;

    cin >> e.v1 >> e.v2 >> e.cost;
    ent = e.cost;

    for (int i = 0;i < M;i++) {
        cin >> e.v1 >> e.v2 >> e.cost;
        road.push_back(e);
    }

    sort(road.begin(), road.end(), cmp);

    for (int i = 0;i < road.size();i++) {
        kruskal(road[i]);
        if (cnt == 0) break;
    }
    if (!ent) ++res;
    ans += res * res;

    for (int i = 0;i <= N;i++) parent[i] = i;
    cnt = N - 1;
    res = 0;

    for (int i = road.size() - 1;i >= 0;i--) {
        kruskal(road[i]);
        if (cnt == 0) break;
    }
    if (!ent) ++res;
    ans -= res * res;

    cout << ans;
    return 0;
}