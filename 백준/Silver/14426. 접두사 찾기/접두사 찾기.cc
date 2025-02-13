#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<string> S;

bool Search(string input) {
    string s;
    int L = 0, R = N - 1, mid;

    while (L <= R) {
        mid = (L + R) / 2;
        s = S[mid];

        if (s.find(input) == 0) return true;

        if (s.compare(input) < 0) L = mid + 1;
        else R = mid - 1;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
    string input;
    cin >> N >> M;
    S.resize(N);

    for (int i = 0; i < N; i++)
        cin >> S[i];
    sort(S.begin(), S.end());

    for (int i = 0; i < M; i++) {
        cin >> input;

        if (Search(input)) ans++;
    }

    cout << ans;
    return 0;
}
