#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;

void Input() {
    int N, M;
    cin >> N >> M;
    v.resize(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> v[i][j];
            v[i][j] += (v[i][j - 1] + v[i - 1][j] - v[i - 1][j - 1]);
        }
    }
}

void Solution() {
    int K, x1, y1, x2, y2;
    cin >> K;

    for (int i = 0; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (v[x2][y2] - v[x2][y1 - 1] - v[x1 - 1][y2] + v[x1 - 1][y1 - 1]) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();

    return 0;
}