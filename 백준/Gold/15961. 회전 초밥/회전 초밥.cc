#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, D, K, C;
vector<int> v, counts;

void Solution() {
    int L = 1, R = K, res = 0, ans = 0;

    for (int i = 0; i < K; i++) {
        if (counts[v[i]] == 0) res++;
        counts[v[i]]++;
    }

    ans = (counts[C] == 0 ? res + 1 : res);

    while (L < N) {
        if (R >= N) R = 0;

        counts[v[L - 1]]--;
        if (counts[v[L - 1]] == 0) res--;
        
        counts[v[R]]++;
        if (counts[v[R]] == 1) res++;

        ans = max(ans, (counts[C] == 0 ? res + 1 : res));

        L++; R++;
    }

    cout << ans;
}

void Input() {
    cin >> N >> D >> K >> C;

    v.resize(N);
    counts.resize(D + 1, 0);

    for (int i = 0; i < N; i++)
        cin >> v[i];
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