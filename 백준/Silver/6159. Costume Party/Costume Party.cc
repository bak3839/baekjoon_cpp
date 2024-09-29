#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
vector<int> len;

void Solution() {
    sort(len.begin(), len.end());

    int ans = 0;

    for (int i = 0; i < N - 1; i++) {
        int l = len[i];

        for (int j = N - 1; j > i; j--) {
            if (len[j] + l <= S) {
                ans += j - i;
                break;
            }
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> S;

    len.resize(N);

    for (int i = 0; i < N; i++)
        cin >> len[i];
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}