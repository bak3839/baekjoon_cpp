#include <iostream>
#include <vector>

using namespace std;

vector<int> volume;
vector<vector<bool>> DP;

void Solution(int N, int M, int S) {
    bool pass = false;
    if (S + volume[0] <= M) DP[0][S + volume[0]] = true;
    if (S - volume[0] >= 0) DP[0][S - volume[0]] = true;

    for (int i = 1;i < N;i++) {
        for (int j = 0;j <= M;j++) {
            if (!DP[i - 1][j]) continue;
            
            if (j + volume[i] <= M) DP[i][j + volume[i]] = true;
            if (j - volume[i] >= 0) DP[i][j - volume[i]] = true;
        }
    }

    for (int i = M;i >= 0;i--) {
        if (DP[N - 1][i]) {
            cout << i;
            pass = true;
            break;
        }     
    }
    if (!pass) cout << -1;
}

void Input(int N, int M) {
    volume.resize(N);
    DP.resize(N, vector<bool>(M + 1, false));

    for (int i = 0;i < N;i++)
        cin >> volume[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, S;
    cin >> N  >> S >> M;
    Input(N, M);
    Solution(N, M, S);
    return 0;
}