#include <iostream>
#include <vector>

using namespace std;

int N, M, dg1, dg2, res = 0;
vector<vector<int>> v(100);
bool visited[100];

int dfs(int x, int cnt) {
	visited[x] = true;
	if (dg2 == x) return cnt;

	for (int i = 0; i < v[x].size(); i++) {
		if (!visited[v[x][i]]) {
			res = dfs(v[x][i], cnt + 1);
		}
	}
	
	if (res > 0) return res;
	else return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int r, c;
	cin >> M;
	cin >> dg1 >> dg2;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> r >> c;
		v[r].push_back(c);
		v[c].push_back(r);
	}
	cout << dfs(dg1, 0);

	return 0;
}