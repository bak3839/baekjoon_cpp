#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> n;
        v.push_back(n);
    }

    int num = N, ans = 0;

    for (int i = N - 1; i >= 0; i--) {
        if (num != v[i]) ans++;
        else num--;
    }

    cout << ans;
    return 0;
}