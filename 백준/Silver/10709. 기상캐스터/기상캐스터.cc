#include <iostream>
#include <vector>

using namespace std;

int H, W;
vector<vector<char>> sky;
vector<vector<int>> ans;

void Solution() {
    for (int i = 0;i < H;i++) {
        for (int j = W - 1; j >= 0; j--) {
            if (sky[i][j] != 'c') continue;

            int cnt = 0;
            ans[i][j] = 0;

            for (int k = j + 1; k < W; k++) {
                if (sky[i][k] == 'c') break;

                ans[i][k] = ++cnt;
            }
        }
    }

    for (int i = 0;i < H;i++) {
        for (int j = 0;j < W;j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }          
}

void Input() {
    cin >> H >> W;

    sky.resize(H, vector<char>(W));
    ans.resize(H, vector<int>(W, -1));

    for (int i = 0;i < H;i++)
        for (int j = 0;j < W;j++)
            cin >> sky[i][j];
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
