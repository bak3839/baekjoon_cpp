#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q, A, B;
    cin >> N >> Q;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    for (int i = 0; i < Q; i++) {
        cin >> A >> B;
        A = lower_bound(v.begin(), v.end(), A) - v.begin();
        B = upper_bound(v.begin(), v.end(), B) - v.begin();
        cout << B - A << "\n";
    }
    return 0;
}
