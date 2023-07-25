#include <iostream>
#include <vector>

using namespace std;

int N, M, ans = 65;
vector<vector<char>> Board;

void Change(int x, int y) {
    bool flag = Board[x][y] == 'W' ? true : false;
    int cnt = 0;

    int tmp = y;
    tmp++;

    for (int i = x; i < x + 8; i++) {
        for (int j = tmp; j < y + 8; j++) {
            if ((flag && Board[i][j] == 'W') || (!flag && Board[i][j] == 'B')) 
                cnt++;

            flag = !flag;
        }
        flag = !flag;
        tmp = y;
    }

    ans = min(ans, cnt);
    ans = min(ans, 64 - cnt);
}

void Solution() {
    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++)
            Change(i, j);
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;

    Board.resize(N, vector<char>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> Board[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}