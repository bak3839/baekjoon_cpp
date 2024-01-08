#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int A, B;
string SA;

void Solution() {
    int ans = -1, n;

    do {
        n = stoi(SA);

        if (SA[0] == '0') continue;

        if (n < B && ans < n) ans = n;
    } while (next_permutation(SA.begin(), SA.end()));

    cout << ans;
}

void Input() {
    cin >> A >> B;
    SA = to_string(A);
    sort(SA.begin(), SA.end());
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
