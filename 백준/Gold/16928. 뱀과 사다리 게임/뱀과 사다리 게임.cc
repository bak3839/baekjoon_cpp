#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, ans;
bool visited[101];
int snakeOrladder[101];

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	visited[1] = true;

	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (now == 100) {
			ans = cnt;
			break;
		}

		for (int i = 1; i <= 6; i++) {
			int next = now + i;

			if (next > 100) break;
			
			if (snakeOrladder[next] > 0) {
				q.push({ snakeOrladder[next], cnt + 1 });				
			}
			else if (!visited[next]) {
				q.push({ next, cnt + 1 });
				visited[next] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x, y;
	cin >> N >> M;
	
	for (int i = 0; i < N + M; i++) {
		cin >> x >> y;
		snakeOrladder[x] = y;
	}

	bfs();
	cout << ans;
	return 0;
}