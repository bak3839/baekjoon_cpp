#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> point;
vector<vector<int>> DP;

void Solution() {
    int ans = 0;

    for (int i = 1; i < N; i++) {
        int max_point = 0;

        for (int k = 0; k < i; k++) 
            max_point = max(max_point, DP[k][i - 1]);

        DP[i][i] = max_point;

        for (int j = i + 1; j < N; j++) {
            int diff = abs(point[j] - point[i]);

            DP[i][j] = max(DP[i][j - 1], max_point + diff);
        }
    }

    for (int i = 0; i < N; i++)
        ans = max(DP[i][N - 1], ans);

    cout << ans;
}

void Input() {
    cin >> N;

    point.resize(N);
    DP.resize(N, vector<int>(N + 1));

    for (int i = 0; i < N; i++) {
        cin >> point[i];

        DP[0][i] = abs(point[0] - point[i]);
    }
        
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}