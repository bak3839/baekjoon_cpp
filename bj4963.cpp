#include <iostream>
#include <vector>

using namespace std;

int w, h;
vector<vector<int>> graph;

void dfs(int x, int y) {
	if ((x >= 0 && x < h) && (y >= 0 && y < w)) {
		if (graph[x][y] == 1) {  // 섬 하나에 연결된 8방향 모두 방문처리
			graph[x][y] = 0; 
			dfs(x, y - 1);
			dfs(x, y + 1);
			dfs(x - 1, y);
			dfs(x + 1, y);

			dfs(x - 1, y - 1);
			dfs(x - 1, y + 1);
			dfs(x + 1, y - 1);
			dfs(x + 1, y + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num;

	while (1) {
		int cnt = 0;
		vector<int> v;

		cin >> w >> h;

		if (!w && !h) break; // 0 0 입력되면 종료

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> num;
				v.push_back(num);
			}

			graph.push_back(v);
			v.clear();
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (graph[i][j] == 1) { // 섬이라면 dfs 시작 8방향 방문처리 시작
					dfs(i, j); 
					++cnt;
				}
			}
		}
		graph.clear();
		cout << cnt << "\n";
	}
	
	return 0;
}