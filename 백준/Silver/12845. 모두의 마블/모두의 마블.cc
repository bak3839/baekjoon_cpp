#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> level;

void Solution() {
    int ans = 0, maxLv = -1, minLv = 100001;
    bool passMax = false, passMin = false;

    for (int i = 0;i < N;i++) {
        maxLv = max(maxLv, level[i]);
        minLv = min(minLv, level[i]);
    }

    ans += maxLv + minLv;

    for (int i = 0;i < N;i++) {
        if (level[i] == maxLv && !passMax) {
            passMax = true;
            continue;
        }

        else if (level[i] == minLv && !passMin) {
            passMin = true;
            continue;
        }

        ans += maxLv + level[i];
    }

    cout << ans;
}

void Input() {
    cin >> N;

    level.resize(N);

    for (int i = 0;i < N;i++)
        cin >> level[i];
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
