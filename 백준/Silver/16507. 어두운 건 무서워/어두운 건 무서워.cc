#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int R, C, Q, x1, x2, y1, y2;
    cin >> R >> C >> Q;
    vector<vector<int>> sum(R + 1, vector<int>(C + 1, 0));

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> sum[i][j];
            sum[i][j] += sum[i][j - 1];
        }
    }

    for (int i = 0; i < Q; i++) {
        int res = 0;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = x1; j <= x2; j++) {
            res += sum[j][y2] - sum[j][y1 - 1];
        }

        cout << res / ((x2 - x1 + 1) * (y2 - y1 + 1)) << "\n";
    }
    return 0;
}