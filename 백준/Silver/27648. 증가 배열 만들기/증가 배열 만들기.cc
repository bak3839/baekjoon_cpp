#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> arr;
int N, M, K;
int mv1[2] = { 1, 0 };
int mv2[2] = { 0, 1 };

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	arr[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int now = arr[x][y];
		q.pop();		

		if (now + 1 > K) break;

		for (int i = 0; i < 2; i++) {
			int nx = x + mv1[i];
			int ny = y + mv2[i];

			if (N <= nx || M <= ny || arr[nx][ny] != 0) continue;

			q.push({ nx, ny });
			arr[nx][ny] = now + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
	arr.resize(N, vector<int>(M, 0));
	bfs();

	if (arr[N - 1][M - 1] != 0) {
		cout << "YES" << "\n";

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else cout << "NO";

	return 0;
}