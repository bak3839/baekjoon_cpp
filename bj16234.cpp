#include <iostream>
#include <algorithm>
#include <queue>
#include  <vector>
#include <cstring>

using namespace std;

short country[50][50];
bool visited[50][50], visited_copy[50][50], pass = false;
int N, L, R;

int mv1[4] = { -1, 1, 0, 0 };
int mv2[4] = { 0, 0, -1, 1 };

// 메인에서 탐색시작을 결정 방문처리가 안된곳이면 실시함

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	vector< pair<int, int>> loc; // 연합된 국가의 좌표 = 나중에 평균을 더해주기 위함

	int cnt = 0, sum = 0;
	sum += country[x][y];
	
	q.push({ x, y });
	loc.push_back({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			// 상 하 좌 우 순서로 진행

			int nx = x + mv1[i];
			int ny = y + mv2[i];

			int gap = abs(country[x][y] - country[nx][ny]);

			if ((nx >= 0 && nx < N) && (ny >= 0 && ny < N)) {
				if (!visited[nx][ny] && L <= gap && gap <= R) {
					++cnt; // 이어진 나라의 수
					visited[nx][ny] = true; // 방문처리
					sum += country[nx][ny]; // 인구수 합하기

					q.push({ nx,ny }); // 다음위치 큐에 저장
					loc.push_back({ nx,ny }); // 평균인원으로 바꿔주기 위한 위치 저장

					pass = true;
				}
			}
		}
	}

	if (cnt != 0) {
		short aver = sum / (cnt + 1);

		for (int i = 0; i < loc.size(); i++) {
			x = loc[i].first;
			y = loc[i].second;

			country[x][y] = aver;
		}
	}

	else loc.pop_back();
	loc.clear();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int day = 0;

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> country[i][j];
		}
	}

	while (1) {
		pass = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) bfs(i, j);
			}
		}

		memset(visited, false, sizeof(visited));

		if (!pass) break;
		++day;
	}

	cout << day;
	return 0;
}