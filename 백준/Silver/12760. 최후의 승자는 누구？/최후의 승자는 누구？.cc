#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> point;
vector<vector<int>> card;

void Solution() {
    int ans = 0;

    for (int i = 0; i < M; i++) {
        int res = 0;

        for (int j = 0; j < N; j++) 
            res = max(res, card[j][i]);

        for (int j = 0; j < N; j++) {
            if (card[j][i] == res) ans = max(ans, ++point[j]);
        }
    }

    for (int i = 0; i < N; i++) {
        if (ans == point[i]) cout << i + 1 << " ";
    }
}

void Input() {
    cin >> N >> M;

    point.resize(N, 0);
    card.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> card[i][j];
        }
        sort(card[i].begin(), card[i].end(), greater<int>());
    }
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}