#include <iostream>
#include <vector>

using namespace std;

int n, m, k, ans;
vector<bool> choice;
vector<vector<int>> skill;

void CountQuest() {
    int res = 0;

    for (int i = 0; i < m; i++) {
        int cnt = 0;

        for (int j = 0; j < k; j++) {
            int s = skill[i][j];

            if (!choice[s]) break;
            cnt++;
        }

        if (cnt == k) res++;
    }

    ans = max(res, ans);
}

void Search(int x, int cnt) {
    if (cnt == n) {
        CountQuest();
        return;
    }

    for (int i = x; i <= 2 * n; i++) {
        choice[i] = true;
        Search(i + 1, cnt + 1);
        choice[i] = false;
    }
}

void Solution() {
    Search(1, 0);

    cout << ans;
}

void Input() {
    cin >> n >> m >> k;

    skill.resize(m, vector<int>(k));
    choice.resize(2 * n + 1, false);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> skill[i][j];
        }
    }
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