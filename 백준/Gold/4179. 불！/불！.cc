#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using vvc = vector<vector<char>>;
using pii = pair<short, short>;

int N, M, sx, sy, ans;
vvc map;
vector<pii> fire;

short mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void bfs() {
    bool pass = false;
    int cnt = 0;
    queue<pii> j;
    queue<pii> f;

    for (int i = 0; i < fire.size(); i++)
        f.push({ fire[i].first, fire[i].second });
    fire.clear();

    j.push({ sx, sy });
    map[sx][sy] = 'x';

    while (!j.empty()) {
        int size = j.size();

        for (int i = 0; i < size; i++) {
            int x = j.front().first;
            int y = j.front().second;
            j.pop();

            if (map[x][y] == 'F') continue;

            if (x == 0 || y == 0 || x == N + 1|| y == M + 1) {
                pass = true; 
                ans = cnt;
                break;
            }

            for (int k = 0; k < 4; k++) {
                int nx = x + mv[k][0];
                int ny = y + mv[k][1];

                if (nx < 0 || ny < 0 || nx > N + 1 || ny > M + 1) continue;
                if (map[nx][ny] == '#' || map[nx][ny] == 'F' || map[nx][ny] == 'x') continue;

                j.push({ nx, ny });
                map[nx][ny] = 'x';
            }
        }
        cnt++;

        if (pass) break;

        if (!f.empty()) {
            int size = f.size();

            for (int i = 0; i < size; i++) {
                int x = f.front().first;
                int y = f.front().second;
                f.pop();

                for (int j = 0; j < 4; j++) {
                    int nx = x + mv[j][0];
                    int ny = y + mv[j][1];

                    if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
                    if (map[nx][ny] == '#' || map[nx][ny] == 'F') continue;

                    f.push({ nx, ny });
                    map[nx][ny] = 'F';
                }
            }
        }    
    }
}

void Solution() {
    bfs();
        
    if (ans != 0) cout << ans;
    else cout << "IMPOSSIBLE";
}

void Input() {
    cin >> N >> M;

    map.resize(N + 2, vector<char>(M + 2, '.'));

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'J') {
                sx = i; sy = j;
            }

            else if (map[i][j] == 'F')
                fire.push_back({ i, j });
        }           
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}
