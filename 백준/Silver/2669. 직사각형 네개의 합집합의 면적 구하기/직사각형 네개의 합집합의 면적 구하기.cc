#include <iostream>
#include <vector>

using namespace std;

void Solution() {
    vector<vector<bool>> map(101, vector<bool>(101, false));
    int x1, y1, x2, y2, ans = 0;

    for (int i = 0; i < 4; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                if (!map[y][x]) {
                    ans++;
                    map[y][x] = true;
                }
            }
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solution();
    return 0;
}
