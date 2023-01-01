#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int visited[100001], res[100001];
vector<vector<int>> tree;

void bfs() {
    queue<int> q;
    visited[1] = true;
    q.push(1);

    while (!q.empty()) {
        int parent = q.front();
        q.pop();

        for (int i = 0; i < tree[parent].size(); i++) {
            int child = tree[parent][i];
            if (!visited[child]) {
                res[child] = parent;
                visited[child] = true;
                q.push(child);
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	int size = N + 1;
	tree.resize(size);
	int a, b;

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
    bfs();

    for (int i = 2; i <= N; i++) cout << res[i] << "\n";
	return 0;
}