#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
    int cost;
    int v1;
    int v2;
}Edge;

vector<Edge> graph;
int parent[200001];
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

bool cmp(Edge e1, Edge e2) {
    if (e1.cost < e2.cost) return true;
    else return false;
}

void kruskal(Edge e) {
    if (!find(e.v1, e.v2)) {
        uni(e.v1, e.v2);
        res += e.cost;
        --cnt;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Edge e;
    int N, M, sum;
    while (1) {
        cin >> N >> M;
        cnt = N - 1;
        sum = 0; res = 0;

        if (!N && !M) break;

        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < M; i++) {
            cin >> e.v1 >> e.v2 >> e.cost;
            graph.push_back(e);
            sum += e.cost;
        }

        sort(graph.begin(), graph.end(), cmp);

        for (int i = 0; i < graph.size(); i++) {
            kruskal(graph[i]);
            if (cnt == 0) break;
        }

        cout << sum - res << "\n";
        graph.clear();
    }
    return 0;
}