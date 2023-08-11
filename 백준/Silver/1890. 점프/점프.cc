#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int N;
vector<vector<int>> map;
vector<vector<ll>> DP;

void Solution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (DP[i][j] == 0 || (i == N - 1 && j == N - 1)) continue;

            int ry = j + map[i][j];
            int dx = i + map[i][j];

            if (ry < N) DP[i][ry] += DP[i][j];
            if (dx < N) DP[dx][j] += DP[i][j];
        }
    }

    cout << DP[N - 1][N - 1];
}

void Input() {
    cin >> N;

    map.resize(N, vector<int>(N));
    DP.resize(N, vector<ll>(N, 0));
    DP[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}