#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector<int> cnt;
vector<string> flr;
vector<vector<char>> tile;

void Solution() {
    int ans = 0;

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            int res = 0, idx; 
          
            for (int x = i; x < N; x = x + K) {
                for (int y = j; y < M; y = y + K) {
                    cnt[flr[x][y] - 65]++;
                }
            }

            for (int t = 0; t < 26; t++) {
                if (res < cnt[t]) {
                    res = cnt[t];
                    idx = t;
                }
            }

            ans += ((N * M) / (K * K)) - res;
            tile[i][j] = 65 + idx;

            fill(cnt.begin(), cnt.end(), 0);
        }
    }

    cout << ans << "\n";
    for (int i = 0; i < N / K; i++) {
        for (int x = 0; x < K; x++) {
            for (int j = 0; j < M / K; j++) {
                for (int y = 0; y < K; y++)
                    cout << tile[x][y];
            }
            cout << "\n";
        }
    }
}

void Input() {
    cin >> N >> M >> K;
    
    string s;
    flr.resize(N);
    cnt.resize(26, 0);
    tile.resize(K, vector<char>(K));

    for (int i = 0; i < N; i++) {
        cin >> flr[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}