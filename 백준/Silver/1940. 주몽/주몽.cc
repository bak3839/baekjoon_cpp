#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, res = 0;

    cin >> N >> M;
    int l = 0, r = N - 1;
    vector<ll> v(N);

    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());

    while (l < r) {
        int sum = v[l] + v[r];
        if (sum == M) {
            ++res;
            ++l; --r;
        }
        else if (sum < M) ++l;
        else --r;
    }
    cout << res;
    return 0;
}