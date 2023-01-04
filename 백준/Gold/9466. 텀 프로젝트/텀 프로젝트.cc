#include <iostream>
#include <vector>

using namespace std;

int cnt;
vector<int> s;
vector<bool> visited;
vector<bool> finish;

void dfs(int x) {
	visited[x] = true;

	if (!visited[s[x]]) {
		dfs(s[x]);
	}

	else if (!finish[s[x]]) {
		for (int i = s[x]; i != x; i = s[i]) cnt++;
		cnt++;
	}
	finish[x] = true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T, n;
	cin >> T;

	while (T--) {
		cin >> n;
		visited.resize(n + 1, false);
		finish.resize(n + 1, false);
		s.resize(n + 1);

		for (int i = 1; i <= n; i++) cin >> s[i];

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) dfs(i);
		}

		cout << n - cnt << "\n";
		cnt = 0;

		visited.clear();
		finish.clear();
		s.clear();
	}
	return 0;
}