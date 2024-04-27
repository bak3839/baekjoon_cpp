#include <iostream>
#include <vector>

using namespace std;

int N, M, ans;
int chicken[3];
vector<vector<int>> preference;

void Calculate() {
    int sum = 0;

    for (int i = 0; i < N; i++) {
        sum += max(preference[i][chicken[0]], max(preference[i][chicken[1]], preference[i][chicken[2]]));
    }

    ans = max(ans, sum);
}

void Search(int x, int index) {
    if (index == 3) {
        Calculate();
        return;
    }

    for (int i = x; i < M; i++) {
        chicken[index] = i;
        Search(i + 1, index + 1);
    }
}

void Solution() {
    Search(0, 0);
    cout << ans;
}

void Input() {
    cin >> N >> M;

    preference.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> preference[i][j];
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