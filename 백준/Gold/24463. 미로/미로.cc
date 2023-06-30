#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N, M;
pii start, goal;
vector<vector<char>> map;
vector<vector<bool>> visit;

int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool dfs(int x, int y) {
    bool pass = false;
    visit[x][y] = true;

    if (x == goal.first && y == goal.second) {
        map[x][y] = '@';
        return true;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];
        
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (visit[nx][ny] || map[nx][ny] == '+') continue;

        pass = dfs(nx, ny);

        if (pass) {
            map[x][y] = '@';
            return true;
        }
    }

    return false;
}

void Solution() {
    dfs(start.first, start.second);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == '@') cout << '.';
            else if (map[i][j] == '.') cout << '@';
            else cout << map[i][j];
        }
        cout << "\n";
    }
}

void Input() {
    int cnt = 0;
    cin >> N >> M;

    map.resize(N, vector<char>(M));
    visit.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == '.' && ((i == 0 || i == N - 1) || (j == 0 || j == M - 1))) {
                if (cnt == 0) {
                    start.first = i;
                    start.second = j;
                }
                else {
                    goal.first = i;
                    goal.second = j;
                }

                cnt++;
            }
        }            
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}