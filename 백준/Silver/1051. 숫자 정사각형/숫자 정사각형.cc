#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<char>> map;

void Solution() {
    int max_len = min(N, M), ans = 1;

    for (int l = 2; l <= max_len; l++) {
        bool pass = false;
        for (int i = 0; i <= N - l; i++) {
            for (int j = 0; j <= M - l; j++) {
                if (map[i][j] == map[i + l - 1][j] &&
                    map[i][j] == map[i][j + l - 1] &&
                    map[i][j] == map[i + l - 1][j + l - 1]) {
                    
                    ans = l;
                    pass = true;
                    break;
                }
            }
            if (pass) break;
        }
    }

    cout << ans * ans;
}

void Input() {
    cin >> N >> M;

    map.resize(N, vector<char>(M));

    for (int i = 0;i < N;i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}
