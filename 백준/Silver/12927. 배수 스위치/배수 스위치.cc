#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    int base = 1, ans = 0;

    cin >> S;

    while (base <= S.size()) {
        if (S[base - 1] == 'Y') {
            for (int i = base - 1; i < S.size(); i += base) {
                S[i] = (S[i] == 'Y' ? 'N' : 'Y');
            }
            ans++;
        }

        base++;
    }
    
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'Y') {
            cout << -1;
            return 0;
        }
    }

    cout << ans;
    return 0;
}
