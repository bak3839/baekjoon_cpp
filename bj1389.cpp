#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> relation(101);
bool visited[101];
int cnt = 0, M, N;
pair<int, int> res = { 1000,101 };

void bfs(int x) {
	int sum = 0;
	int j;

	for (j = 1; j <= N; j++) {
		if (j == x) continue;

		bool pass = false;
		int cnt = 0;

		queue <pair<int, int>> q;
		q.push({ x,1 });

		visited[x] = true;

		while (!q.empty()) {
			int fr = q.front().first;
			cnt = q.front().second;
			q.pop();

			for (int i = 0; i < relation[fr].size(); i++) {
				int next = relation[fr][i];

				if (next == j) {
					pass = true;
					break;
				}

				if (!visited[next]) {
					q.push({ next ,cnt + 1 });
					visited[next] = true;
				}
			}
			if (pass) break;
		}
		sum += cnt;
		memset(visited, false, sizeof(visited));
	}

	if (res.first > sum) {
		res.first = sum;
		res.second = x;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	int r, c;

	for (int i = 0; i < M; i++) {
		cin >> r >> c;
		relation[r].push_back(c);
		relation[c].push_back(r);
	}

	for (int i = 1; i <= N; i++) {
		bfs(i);
	}

	cout << res.second;
	return 0;
}