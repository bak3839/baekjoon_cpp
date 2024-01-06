#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string S;

void Solution() {
    int ans = 0;

    do {
        bool pass = true;

        for (int i = 1; i < S.size(); i++) {
            if (S[i - 1] == S[i]) {
                pass = false;
                break;
            }
        }

        if (pass) ans++;
    } while (next_permutation(S.begin(), S.end()));

    cout << ans;
}

void Input() {
    cin >> S;
    sort(S.begin(), S.end());
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
