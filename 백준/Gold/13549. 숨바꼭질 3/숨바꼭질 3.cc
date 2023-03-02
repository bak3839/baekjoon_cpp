#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
bool visited[100001];
int N, K;

void bfs(int s) {
	queue<pair<int, int>> q;
	q.push({s, 0});
	visited[s] = true;

	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (now == K) {
			cout << cnt;
			break;
		}

		if (now * 2 <= 100000 && !visited[now * 2]) {
			q.push({ now * 2, cnt });
			visited[now * 2] = true;
		}

		if (0 <= now - 1 && now - 1 <= 100000 && !visited[now - 1]) {
			q.push({ now - 1, cnt + 1 });
			visited[now - 1] = true;
		}

		if (now + 1 <= 100000 && !visited[now + 1]) {
			q.push({ now + 1, cnt + 1 });
			visited[now + 1] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	bfs(N);
	return 0;
}