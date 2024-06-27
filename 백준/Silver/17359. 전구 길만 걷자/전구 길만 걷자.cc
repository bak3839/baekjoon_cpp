#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, ans = 2100000000, base;
vector<string> bulb;
vector<bool> choice;

void Search(int cnt, int res, string road) {
    if (cnt == N) {
        ans = min(ans, res);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (choice[i]) continue;

        int tmp = 0;

        if (road.size() != 0) {
            tmp = road[road.size() - 1] != bulb[i][0] ? 1 : 0;
        }

        choice[i] = true;
        Search(cnt + 1, res + tmp, bulb[i]);
        choice[i] = false;
    }
}

void Solution() {
    Search(0, 0, "");

    cout << ans + base;
}

void Input() {
    cin >> N;

    bulb.resize(N);
    choice.resize(N, false);

    for (int i = 0; i < N; i++) {
        cin >> bulb[i];

        for (int j = 0; j < bulb[i].size() - 1; j++) {
            if (bulb[i][j] != bulb[i][j + 1]) base++;
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