#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int A, B, N;
vector<int> btn;

void Solution() {
    int ans = abs(A - B);

    for (int i = 0; i < N; i++)
        ans = min(ans, abs(btn[i] - B) + 1);

    cout << ans;
}

void Input() {
    cin >> A >> B >> N;

    btn.resize(N);

    for (int i = 0; i < N; i++)
        cin >> btn[i];
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
