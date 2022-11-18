#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

typedef struct {
    int cost;
    int v1;
    int v2;
}Edge;

vector<Edge> road;
int parent[100001];
int cnt;
ll res;

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
    int N, M;
    ll sum = 0;
    cin >> N >> M;
    cnt = N - 1;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        cin >> e.v1 >> e.v2 >> e.cost;
        sum += e.cost;
        road.push_back(e);
    }

    sort(road.begin(), road.end(), cmp);

    for (int i = 0; i < road.size(); i++) {
        kruskal(road[i]);
        if (cnt == 0) break;
    }

    if (cnt != 0) cout << -1;
    else cout << sum - res;

	return 0;
}