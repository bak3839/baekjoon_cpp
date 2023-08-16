#include <iostream>
#include <vector>

using namespace std;

int N, M, K, ans = -40001;
vector<vector<int>> num;
vector<vector<int>> poss;

void ChangeStatus(int x, int y, int n) {
    int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    for (int i = 0; i < 4; i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

        poss[nx][ny] += n;
    }
}

void Search(int x, int y, int cnt, int sum) {  
    if (cnt == K) {
        ans = max(sum, ans);
        return;
    }

    int tmp = y;

    for (int i = x; i < N; i++) {
        for (int j = tmp; j < M; j++) {
            if (poss[i][j] > 0) continue;

            ChangeStatus(i, j, 1);
            Search(i, j + 1, cnt + 1, sum + num[i][j]);
            ChangeStatus(i, j, -1);
        }
        tmp = 0;
    }
}

void Solution() {
    Search(0, 0, 0, 0);

    cout << ans;
}

void Input() {
    cin >> N >> M >> K;

    num.resize(N, vector<int>(M));
    poss.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> num[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}