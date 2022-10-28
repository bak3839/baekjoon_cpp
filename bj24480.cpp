#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<vector<int>> v(100001);
vector<int> res(100001, 0);
bool visited[100001];
int cnt = 1;

void dfs(int s) {
	res[s] = cnt++;
	visited[s] = true;

	for (int i = 0;i < v[s].size();i++) {
		if (!visited[v[s][i]]) dfs(v[s][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, R, n, r;
	cin >> N >> M >> R;	

	for (int i = 1;i <= M;i++) {
		cin >> r >> n;
		v[r].push_back(n);
		v[n].push_back(r);
	}

	for (int i = 1;i <= N;i++) {
		sort(v[i].begin(), v[i].end(), greater<int>());
	}

	dfs(R);

	for (int i = 1;i <= N;i++) cout << res[i] << "\n";

	return 0;
}