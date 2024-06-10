#include <iostream>
#include <vector>

using namespace std;

int N, M, T;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<vector<int>> image;

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M || image[nx][ny] == 0) continue;

        image[nx][ny] = 0;
        dfs(nx, ny);
    }
}

void Solution() {
    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (image[i][j] >= T) image[i][j] = 255;
            else image[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (image[i][j] == 0) continue;

            image[i][j] = 0;
            dfs(i, j);
            ans++;
        }
    }

    cout << ans;
}

void Input() {
    int r, g, b;
    cin >> N >> M;

    image.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {       
        for (int j = 0; j < M; j++) {
            cin >> r >> g >> b;
            image[i][j] = (r + g + b) / 3;
        }
    }
        
    cin >> T;
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}