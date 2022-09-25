#include <iostream>
#include <vector>

using namespace std;

int M, N;
vector<vector<short>> graph(1000);
bool visited[1000];

void dfs(int index) {
	for (int i = 0; i < graph[index].size(); i++) {
		if (!visited[graph[index][i]]) {
			visited[graph[index][i]] = true;
			dfs(graph[index][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	short num, vertex;
	int cnt = 0;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> vertex >> num;
		graph[vertex - 1].push_back(num - 1);
		graph[num - 1].push_back(vertex - 1);
	}
	
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i);
			++cnt;
		}
	}

	cout << cnt;
	return 0;
}