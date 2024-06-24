#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int N, ans = 100001;
vector<int> pay;
vector<bool> choice;
vector<vector<pii>> DC;

void Discount(int n, bool state) {
    for (int i = 0; i < DC[n].size(); i++) {
        int c = DC[n][i].first;
        int d = DC[n][i].second;

        if (state) pay[c] -= d;
        else pay[c] += d;
    }
}

void Search(int sum, int cnt) {
    if (cnt == N) {
        ans = min(ans, sum);
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (choice[i]) continue;

        choice[i] = true;
        Discount(i, true);

        Search(sum + (pay[i] > 0 ? pay[i] : 1), cnt + 1);

        choice[i] = false;
        Discount(i, false);
    }
}

void Solution() {
    Search(0, 0);

    cout << ans;
}

void Input() {
    int p, c, d;
    cin >> N;

    DC.resize(N + 1);
    pay.resize(N + 1);
    choice.resize(N + 1, false);

    for (int i = 1; i <= N; i++)
        cin >> pay[i];

    for (int i = 1; i <= N; i++) {
        cin >> p;

        for (int j = 0; j < p; j++) {
            cin >> c >> d;

            DC[i].push_back({ c, d });
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