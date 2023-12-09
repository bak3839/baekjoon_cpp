#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> g;

void Solution() {
    int sum = 1;

    for (int i = 0; i < N; i++) {
        if (sum < g[i]) break;

        sum += g[i];
    }

    cout << sum;
}

void Input() {
    cin >> N;

    g.resize(N);

    for (int i = 0; i < N; i++)
        cin >> g[i];
    sort(g.begin(), g.end());
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
