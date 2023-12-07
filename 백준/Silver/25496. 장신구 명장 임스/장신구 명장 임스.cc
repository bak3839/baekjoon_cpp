#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, P;
vector<int> A;

void Solution() {
    int ans = 0;

    for (int i = 0;i < N;i++) {
        if (P >= 200) break;

        P += A[i];
        ans++;
    }

    cout << ans;
}

void Input() {
    cin >> P >> N;

    A.resize(N);

    for (int i = 0;i < N;i++)
        cin >> A[i];
    sort(A.begin(), A.end());
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
