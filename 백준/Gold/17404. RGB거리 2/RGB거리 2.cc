#include <iostream>
#include <vector>

using namespace std;

int N;
int cost[1001][3];
int DP[1001][3];

void Solution() {
    int ans = 100000000;

    for (int k = 0; k < 3; k++) {
        int color = cost[1][k];
        
        for (int l = 0; l < 3; l++) {
            if (k == l) {
                DP[2][l] = 10000;
                continue;
            }

            DP[2][l] = cost[2][l] + color;
        }

        for (int i = 3; i <= N; i++) {
            for (int j = 0; j < 3; j++) {              
                int c = cost[i][j];

                if (j == 0) DP[i][j] = min(c + DP[i - 1][1], c + DP[i - 1][2]);
                else if (j == 1) DP[i][j] = min(c + DP[i - 1][0], c + DP[i - 1][2]);
                else if (j == 2) DP[i][j] = min(c + DP[i - 1][0], c + DP[i - 1][1]);
            }
        }

        if (k == 0) ans = min(DP[N][1], min(ans, DP[N][2]));
        else if (k == 1) ans = min(DP[N][0], min(ans, DP[N][2]));
        else ans = min(DP[N][0], min(ans, DP[N][1]));
    }
    cout << ans;
}

void Input() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++)
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