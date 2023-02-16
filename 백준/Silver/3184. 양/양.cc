#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N, M, wolf, sheep;
char map[250][250];
bool visited[250][250];

int mv1[4] = { -1, 1, 0 ,0 };
int mv2[4] = { 0, 0, -1, 1 };

void bfs(int x, int y) {
    int w = 0, s = 0;

    queue<pii> q;
    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (map[x][y] == 'v') ++w;
        else if (map[x][y] == 'o') ++s;

        for (int i = 0; i < 4; i++) {
            int nx = x + mv1[i];
            int ny = y + mv2[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (!visited[nx][ny] && map[nx][ny] != '#') {
                    q.push({ nx, ny });
                    visited[nx][ny] = true;
                }
            }
        }
    }

    if (w < s) sheep += s;
    else wolf += w;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    char ch;
    vector<pii> v;
    vector<pii> s;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> ch;
            map[i][j] = ch;
            if (ch == 'v') v.push_back({ i, j });
            else if (ch == 'o') s.push_back({ i, j });
        }
    }

    for (int i = 0; i < v.size(); i++) {
        int x = v[i].first;
        int y = v[i].second;

        if (!visited[x][y]) bfs(x, y);
    }

    for (int i = 0; i < s.size(); i++) {
        int x = s[i].first;
        int y = s[i].second;

        if (!visited[x][y]) bfs(x, y);
    }

    cout << sheep << " " << wolf;
    return 0;
}