#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, ans = 3001;
int mv[4][2] = { {0, 1},{-1, 0},{0, -1},{1, 0} };
vector<vector<int>> cost;
vector<vector<bool>> visit;

bool Blossom_test(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];

        if (visit[nx][ny]) return false;
    }

    return true;
}

int Blossom(int x, int y) {
    
    int sum = 0;

    sum += cost[x][y];
    visit[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];

        sum += cost[nx][ny];
        visit[nx][ny] = true;
    }

    return sum;
}

void Delete(int x, int y) {
    visit[x][y] = false;

    for (int i = 0; i < 4; i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];

        visit[nx][ny] = false;
    }
}

void Search(int x, int y, int sum, int cnt) {
    if (cnt == 3) {
        ans = min(sum, ans);
        return;
    }
    int s = y;

    for (int i = x; i < N - 1; i++) {
        for (int j = s; j < N - 1; j++) {
            if (visit[i][j] || !Blossom_test(i, j)) continue;
            Search(i, j + 1, sum + Blossom(i, j), cnt + 1);
            Delete(i, j);
        }
        s = 1;
    }
}

void Solution() {
    Search(1, 1, 0, 0);
    cout << ans;
}

void Input() {
    cin >> N;
    cost.resize(N, vector<int>(N));
    visit.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> cost[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}