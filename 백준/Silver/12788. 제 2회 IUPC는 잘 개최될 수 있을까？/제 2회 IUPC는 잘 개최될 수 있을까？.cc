#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, K;
vector<int> pen;

void Solution() {
    int total = M * K, index = 0, ans = 0;

    while (index < N && total > 0) {
        ans++;
        total -= pen[index++];
    }

    if (total > 0) cout << "STRESS";
    else cout << ans;
}

void Input() {
    cin >> N >> M >> K;
    
    pen.resize(N);

    for (int i = 0; i < N; i++)
        cin >> pen[i];
    sort(pen.begin(), pen.end(), greater<int>());
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
