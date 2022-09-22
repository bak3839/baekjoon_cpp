#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

char graph[20][20];
bool alpha[26];
int res = 0, r, c;

int mv1[4] = { -1, 1, 0, 0 };
int mv2[4] = { 0, 0, -1, 1 };

void dfs(int x, int y, int cnt) {

	res = max(res, cnt); // 최대값 반환

    for (int i = 0; i < 4; i++) {
        // 상 하 좌 우 순서로 진행

        int nx = x + mv1[i];
        int ny = y + mv2[i];

        if ((nx >= 0 && nx < r) && (ny >= 0 && ny < c)) { // 범위가 넘어가면 무시
			if (alpha[graph[nx][ny] - 'A']) {
				alpha[graph[nx][ny] - 'A'] = false; // dfs 전에 방문처리 
				dfs(nx, ny, cnt + 1); // 카운트 해주면서 넘어가기
				alpha[graph[nx][ny] - 'A'] = true; // 다돌고 방문처리 풀기
			} 
        }
    }
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> graph[i][j];
			alpha[graph[i][j] - 65] = true;
		}
	}

	alpha[graph[0][0] - 'A'] = false; // 방문처리
	dfs(0, 0, 1);

	cout << res;
	return 0;
}