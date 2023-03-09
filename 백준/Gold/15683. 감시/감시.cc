#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N, M, blind, ans = 100;
vector<vector<int>> map;
vector<pii> cctv;

void solution(int start);

void move1(int x, int y) { // 상
	for (int j = x - 1; j >= 0; j--) {
		if (map[j][y] == 6) break;
		if (0 < map[j][y] && map[j][y] < 6) continue;
		if (map[j][y] >= 7) map[j][y]++;
		else {
			map[j][y] = 7;
			blind--;
		}
	}
}
void back1(int x, int y) {
	for (int j = x - 1; j >= 0; j--) {
		if (map[j][y] == 6) break;
		if (0 < map[j][y] && map[j][y] < 6) continue;
		if (map[j][y] > 7) map[j][y]--;
		else {
			map[j][y] = 0;
			blind++;
		}
	}
}

void move2(int x, int y) { // 하
	for (int j = x + 1; j < N; j++) {
		if (map[j][y] == 6) break;
		if (0 < map[j][y] && map[j][y] < 6) continue;
		if (map[j][y] >= 7) map[j][y]++;
		else {
			map[j][y] = 7;
			blind--;
		}
	}
}
void back2(int x, int y) {
	for (int j = x + 1; j < N; j++) {
		if (map[j][y] == 6) break;
		if (0 < map[j][y] && map[j][y] < 6) continue;
		if (map[j][y] > 7) map[j][y]--;
		else {
			map[j][y] = 0;
			blind++;
		}
	}
}

void move3(int x, int y) { // 우
	for (int j = y + 1; j < M; j++) {
		if (map[x][j] == 6) break;
		if (0 < map[x][j] && map[x][j] < 6) continue;
		if (map[x][j] >= 7) map[x][j]++;
		else {
			map[x][j] = 7;
			blind--;
		}
	}
}
void back3(int x, int y) {
	for (int j = y + 1; j < M; j++) {
		if (map[x][j] == 6) break;
		if (0 < map[x][j] && map[x][j] < 6) continue;
		if (map[x][j] > 7) map[x][j]--;
		else {
			map[x][j] = 0;
			blind++;
		}
	}
}

void move4(int x, int y) { // 좌
	for (int j = y - 1; j >= 0; j--) {
		if (map[x][j] == 6) break;
		if (0 < map[x][j] && map[x][j] < 6) continue;
		if (map[x][j] >= 7) map[x][j]++;
		else {
			map[x][j] = 7;
			blind--;
		}
	}
}
void back4(int x, int y) {
	for (int j = y - 1; j >= 0; j--) {
		if (map[x][j] == 6) break;
		if (0 < map[x][j] && map[x][j] < 6) continue;
		if (map[x][j] > 7) map[x][j]--;
		else {
			map[x][j] = 0;
			blind++;
		}
	}
}

void cctv1(int idx) {
	int x = cctv[idx].first;
	int y = cctv[idx].second;

	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			move1(x, y);
			solution(idx + 1);
			back1(x, y);
		}

		else if (i == 1) {
			move2(x, y);
			solution(idx + 1);
			back2(x, y);
		}
		else if (i == 2) {
			move3(x, y);
			solution(idx + 1);
			back3(x, y);
		}
		else if (i == 3) {
			move4(x, y);
			solution(idx + 1);
			back4(x, y);
		}
	}
}

void cctv2(int idx) {
	int x = cctv[idx].first;
	int y = cctv[idx].second;

	for (int i = 0; i < 2; i++) {
		if (i == 0) {
			move1(x, y);
			move2(x, y);
			solution(idx + 1);
			back1(x, y);
			back2(x, y);
		}
		else if (i == 1) {
			move3(x, y);
			move4(x, y);
			solution(idx + 1);
			back3(x, y);
			back4(x, y);
		}
	}
}
void cctv3(int idx) {
	int x = cctv[idx].first;
	int y = cctv[idx].second;

	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			move1(x, y);
			move3(x, y);
			solution(idx + 1);
			back1(x, y);
			back3(x, y);
		}
		else if (i == 1) {
			move3(x, y);
			move2(x, y);
			solution(idx + 1);
			back3(x, y);
			back2(x, y);
		}
		else if (i == 2) {
			move4(x, y);
			move2(x, y);
			solution(idx + 1);
			back4(x, y);
			back2(x, y);
		}
		else if (i == 3) {
			move1(x, y);
			move4(x, y);
			solution(idx + 1);
			back1(x, y);
			back4(x, y);
		}
	}
}
void cctv4(int idx) { // 상하우좌
	int x = cctv[idx].first;
	int y = cctv[idx].second;

	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			move1(x, y);
			move3(x, y);
			move4(x, y);
			solution(idx + 1);
			back1(x, y);
			back3(x, y);
			back4(x, y);
		}
		else if (i == 1) {
			move1(x, y);
			move3(x, y);
			move2(x, y);
			solution(idx + 1);
			back1(x, y);
			back3(x, y);
			back2(x, y);
		}
		else if (i == 2) {
			move2(x, y);
			move3(x, y);
			move4(x, y);
			solution(idx + 1);
			back2(x, y);
			back3(x, y);
			back4(x, y);
		}
		else if (i == 3) {
			move1(x, y);
			move2(x, y);
			move4(x, y);
			solution(idx + 1);
			back1(x, y);
			back2(x, y);
			back4(x, y);
		}
	}
}

void cctv5(int x, int y) {
	move1(x, y);
	move2(x, y);
	move3(x, y);
	move4(x, y);
}

void solution(int start) {
	for (int i = start; i < cctv.size(); i++) {
		int x = cctv[i].first;
		int y = cctv[i].second;

		switch (map[x][y]) {
		case 1:
			cctv1(i);
			break;
		case 2:
			cctv2(i);
			break;
		case 3:
			cctv3(i);
			break;
		case 4:
			cctv4(i);
			break;
		
		}
	}

	ans = min(ans, blind);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	map.resize(N, vector<int>(M));
	vector<pii> v;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) blind++;
			else if (0 < map[i][j] && map[i][j] < 5) cctv.push_back({ i, j });
			else if (map[i][j] == 5) v.push_back({ i, j });
		}
	}
	
	for (int i = 0; i < v.size(); i++) cctv5(v[i].first, v[i].second);

	solution(0);
	cout << ans;
	return 0;
}