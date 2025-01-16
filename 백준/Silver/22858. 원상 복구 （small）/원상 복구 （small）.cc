#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;

    cin >> N >> K;

    vector<int> D(N + 1), S(N + 1);

    for (int i = 1; i <= N; i++) cin >> S[i];
    for (int i = 1; i <= N; i++) cin >> D[i];

    for (int i = 1; i <= K; i++) {
        vector<int> tmp(S);

        for (int j = 1; j <= N; j++) {          
            S[D[j]] = tmp[j];
        }
    }

    for (int i = 1; i <= N; i++)
        cout << S[i] << " ";

    return 0;
}