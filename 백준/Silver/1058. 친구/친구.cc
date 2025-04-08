#include <bits/stdc++.h>

using namespace std;

int N, ans;
string S[51];

bool check(int A, int B) {
    if (A == B) return false;

    for (int i = 0; i < N; i++) {
        if (S[i][A] == 'Y' && S[i][B] == 'Y') return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> S[i];

    for (int i = 0; i < N; i++) {
        int res = 0;

        for (int j = 0; j < N; j++) {
            if ((S[i][j] == 'Y' && S[j][i] == 'Y') || check(i, j)) res++;
        }

        ans = max(ans, res);
    }

    cout << ans;
    return 0;
}