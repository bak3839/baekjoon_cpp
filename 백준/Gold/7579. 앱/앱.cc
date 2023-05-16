#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N, M, sum;
vector<vector<int>> DP;
vector<pii> app;

void Solution() {
    int m, c;

    for (int i = 1; i <= N; i++) {
        m = app[i].first; c = app[i].second;

        for (int j = 0; j <= sum; j++) {
            if (j - c >= 0) DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - c] + m);
            else DP[i][j] = max(DP[i][j], DP[i - 1][j]);
        }
    }

    for (int i = 0; i <= sum; i++) {
        if (DP[N][i] >= M) {
            cout << i;
            break;
        }
    }
}

void Input() {
    cin >> N >> M;
    app.resize(N + 1);
    
    for (int i = 1; i <= N; i++) cin >> app[i].first;
    for (int i = 1; i <= N; i++) {
        cin >> app[i].second;
        sum += app[i].second;
    }
    DP.resize(N + 1, vector<int>(sum + 1, 0));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}