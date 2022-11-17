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
int parent[301];
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
        res += e.cost;
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
    int N, w, cost = 100001;
    cin >> N;
    cnt = N;

    for (int i = 0; i < N; i++) {
        cin >> w;
        e.v1 = 0; e.v2 = i + 1; e.cost = w;
        road.push_back(e);
        parent[i] = i;
    }
    parent[N] = N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> w;
            if (j >= i) continue;
            e.v1 = i; e.v2 = j; e.cost = w;
            road.push_back(e);
        }
    }

    sort(road.begin(), road.end(), cmp);

    for (int i = 0; i < road.size(); i++) {
        kruskal(road[i]);
        if (cnt == 0) break;
    }

    cout << res;
    return 0;
}