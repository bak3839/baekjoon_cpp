#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

void Solution() {
    int ans = 210000000;

    for (int i = 0; i < N; i++) 
        ans = min(ans, v[i] + v[N * 2 - i - 1]);
    cout << ans;
}

void Input() {
    cin >> N;

    v.resize(N * 2);

    for (int i = 0; i < 2 * N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
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
