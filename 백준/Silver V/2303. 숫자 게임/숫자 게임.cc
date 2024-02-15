#include <iostream>
#include <vector>

using namespace std;

int N, ans, res;
vector<vector<int>> card;

void Search(int x, int sum, int cnt, int p) {
    if (cnt == 3) {
        if (res <= sum % 10) {
            res = sum % 10;
            ans = p + 1;
        }
        return;
    }

    for (int i = x; i < 5; i++) {
        Search(i + 1, sum + card[p][i], cnt + 1, p);
    }
}

void Solution() {
    for (int i = 0; i < N; i++)
        Search(0, 0, 0, i);

    cout << ans;
}

void Input() {
    cin >> N;
    
    card.resize(N, vector<int>(5));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < 5; j++)
            cin >> card[i][j];
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
