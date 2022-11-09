#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct{
    int cost;
    int v1;
    int v2;   
}Edge;

vector<Edge> graph;
int parent[1001];
int res;

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

bool cmp(Edge e1, Edge e2) {
    if (e1.cost < e2.cost) return true;
    else return false;
}

void kruskal(Edge e) {
    if (!find(e.v1, e.v2)) {
        uni(e.v1, e.v2);
        res += e.cost;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Edge e;
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 0; i < M; i++) {
        cin >> e.v1 >> e.v2 >> e.cost;
        graph.push_back(e);
    }

    sort(graph.begin(), graph.end(), cmp);

    for (int i = 0; i < M; i++) kruskal(graph[i]);

    cout << res;
    return 0;
}