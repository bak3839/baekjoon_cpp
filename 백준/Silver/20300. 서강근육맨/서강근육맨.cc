#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int N;
vector<ll> t;

void Solution() {
    ll ans = 0;
    int end = N / 2, index = N - 1;

    if (N % 2) {
        end = (N - 1) / 2;
        ans = t[index];
        index--;        
    }

    for (int i = 0; i < end; i++) 
        ans = max(ans, t[i] + t[index--]);

    cout << ans;
}

void Input() {
    cin >> N;

    t.resize(N);

    for (int i = 0; i < N; i++)
        cin >> t[i];
    sort(t.begin(), t.end());
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
