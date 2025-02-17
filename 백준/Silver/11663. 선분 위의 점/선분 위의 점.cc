#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, s, e;
    cin >> N >> M;

    vector<int> S(N);

    for (int i = 0; i < N; i++)
        cin >> S[i];
    sort(S.begin(), S.end());

    for (int i = 0; i < M; i++) {
        cin >> s >> e;

        s = lower_bound(S.begin(), S.end(), s) - S.begin();
        e = upper_bound(S.begin(), S.end(), e) - S.begin();
        cout << e - s << "\n";
    }

    return 0;
}
