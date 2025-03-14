#include <bits/stdc++.h>

using namespace std;

string num;

int Solve() {
    int index = 0, len = num.size(), N = 1;

    while (index < len) {
        string n = to_string(N);

        for (int i = 0; i < n.size(); i++) {
            if (num[index] == n[i]) {
                index++;
            }
            if (index >= len) return N;
        }
        N++;
    }

    return N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num;
    cout << Solve();
    return 0;
}
