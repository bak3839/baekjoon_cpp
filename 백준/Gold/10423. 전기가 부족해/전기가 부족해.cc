#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
    int cost;
    int v1;
    int v2;
}Edge;

vector<int> power(1001, 0);
vector<Edge> graph;
int parent[1001];
int res, target;

int getRoot(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
}

void uni(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);
    if (power[a]) parent[b] = a;
    else if (power[b]) parent[a] = b;
    else if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool find(int a, int b) {
    a = getRoot(a);
    b = getRoot(b);
    if (a == b) return true;
    else return false;
}

bool cmp(Edge e1, Edge e2) {
    if (e1.cost < e2.cost) return true;
    else return false;
}

void kruskal(Edge e) {
    int cnt = 0;

    if (power[e.v1] || power[getRoot(e.v1)]) ++cnt;
    if (power[e.v2] || power[getRoot(e.v2)]) ++cnt;

    if (!find(e.v1, e.v2) && cnt < 2) {
        uni(e.v1, e.v2);
        res += e.cost;
        target--;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Edge e;
    int N, M, K, n;
    cin >> N >> M >> K;
    target = N - K;

    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 0; i < K; i++) {
        cin >> n;
        power[n] = 1;
    }

    for (int i = 0; i < M; i++) {
        cin >> e.v1 >> e.v2 >> e.cost;
        if (power[e.v1] && power[e.v2]) continue;
        graph.push_back(e);
    }

    sort(graph.begin(), graph.end(), cmp);

    for (int i = 0; i < graph.size(); i++) {
        kruskal(graph[i]);
        if (target == 0) break;
    }

    cout << res;
    return 0;
}   