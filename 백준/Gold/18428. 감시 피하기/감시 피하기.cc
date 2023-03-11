#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int N;
vector<vector<char>> map;
vector<pii> teacher;

bool watch(int x, int y) {
	for (int i = x - 1; i >= 0; i--) {
		if (map[i][y] == 'O') break;
		if (map[i][y] == 'S') return false;
	}
	for (int i = x + 1; i < N; i++) {
		if (map[i][y] == 'O') break;
		if (map[i][y] == 'S') return false;
	}
	for (int i = y - 1; i >= 0; i--) {
		if (map[x][i] == 'O') break;
		if (map[x][i] == 'S') return false;
	}
	for (int i = y + 1; i < N; i++) {
		if (map[x][i] == 'O') break;
		if (map[x][i] == 'S') return false;
	}
	return true;
}

bool search() {
	int cnt = 0;

	for (int i = 0; i < teacher.size(); i++) {
		int x = teacher[i].first;
		int y = teacher[i].second;

		if (watch(x, y)) cnt++;
	}
	if (cnt == teacher.size()) return true;
	else return false;
}

bool wall(int cnt, int x, int y) {
	bool pass = false;

	for (int i = x; i < N; i++) {
		for (int j = y; j < N; j++) {
			if (map[i][j] != 'X') continue;
			cnt++;
			map[i][j] = 'O';

			if (cnt == 3) {
				pass = search();
				if (pass) break;
			}
			else {
				pass = wall(cnt, i, j);
				if (pass) break;
			}

			cnt--;
			map[i][j] = 'X';
		}
		y = 0;
		if (pass) break;
	}
	return pass;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	map.resize(N, vector<char>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'T') teacher.push_back({ i, j });
		}
	}
	
	bool pass = wall(0, 0, 0);

	if (pass) cout << "YES";
	else cout << "NO";
	return 0;
}