#include <iostream>
#include <vector>

using namespace std;

int H, W, rain, ans;
vector<vector<int>> block;

void Solution() {
    for (int i = 0; i < H; i++) {
        if (block[i][0] == 1) break;

        for (int j = 0; j < W; j++) {
            if (block[i][j] == 1 || block[i][j] == 2) break;

            block[i][j] = 2;
            ans--;
        }
    }

    for (int i = 0; i < H; i++) {
        if (block[i][W - 1] == 1) break;

        for (int j = W - 1; j >= 0; j--) {
            if (block[i][j] == 1 || block[i][j] == 2) break;

            block[i][j] = 2;
            ans--;
        }
    }

    cout << ans;
}

void Input() {
    int n;
    cin >> H >> W;

    block.resize(H, vector<int>(W, 1));

    for (int i = 0; i < W; i++) {
        cin >> n;

        n = H - n;
        ans += n;

        for (int j = 0; j < n; j++)
            block[j][i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}