#include <iostream>
#include <vector>

using namespace std;

int N, M, ans = -200001;
vector<int> pick;
vector<vector<int>> compatibility;

void Calculate() {
    int sum = 0, c1, c2;

    for (int i = 0; i < M - 1; i++) {
        for (int j = i + 1; j < M; j++) {
            c1 = pick[i]; c2 = pick[j];

            sum += compatibility[c1][c2];
        }
    }

    ans = max(sum, ans);
}

void Search(int x) {
    if (pick.size() == M) {
        Calculate();
        return;
    }

    for (int i = x; i < N; i++) {
        pick.push_back(i);
        Search(i + 1);
        pick.pop_back();
    }
}

void Solution() {
    Search(0);

    cout << ans;
}

void Input() {
    cin >> N >> M;

    compatibility.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> compatibility[i][j];
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