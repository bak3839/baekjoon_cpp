#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, a, b;
    vector<pii> v;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        if (b < a) v.push_back({ b, a });
    }

    sort(v.begin(), v.end());

    ll ans = M;
    int left = -1, right = -1;
    for (int i = 0; i < v.size(); i++) {
        pii p = v[i];

        if (p.first > right) {
            ans += (right - left) * 2;
            left = p.first;
            right = p.second;
        }
        else {
            right = max(right, p.second);
        }
    }
    ans += (right - left) * 2;

    cout << ans;
    return 0;
}