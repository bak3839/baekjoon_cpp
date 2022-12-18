#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
	int v1;
	int v2;
	int cost;
}Edge;

vector<Edge> road;
int parent[10001];
int N, M, u, v, cnt;
bool connect;

bool cmp(Edge e1, Edge e2) {
	if (e1.cost < e2.cost) return true;
	else return false;
}

int getRoot(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = getRoot(parent[x]);
}

void uni(int a, int b) {
	a = getRoot(a);
	b = getRoot(b);
	if (a < b) parent[b] = a;
	else if (a > b) parent[a] = b;
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
		cnt++;
		if ((e.v1 == u && e.v2 == v) || (e.v1 == v && e.v2 == u)) connect = true;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	Edge e;

	while (T--) {	
		cnt = 0;
		connect = false;
		cin >> N >> M >> u >> v;

		for (int i = 0; i < M; i++) {
			cin >> e.v1 >> e.v2 >> e.cost;
			road.push_back(e);
		}
		sort(road.begin(), road.end(), cmp);

		for (int i = 1; i <= N; i++) parent[i] = i;

		for (int i = 0; i < road.size(); i++) {
			if (cnt == N - 1) break;
			kruskal(road[i]);
		}
		road.clear();
		if (connect) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}