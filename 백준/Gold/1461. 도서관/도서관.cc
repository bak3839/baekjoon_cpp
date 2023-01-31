#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M, res = 0, cnt = 0;
    bool flag = true;
    cin >> N >> M;

    vector<int> v(N);

    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int l = 0, r = N - 1, k;

    while (l <= r) {
        if (abs(v[l]) > abs(v[r])) {
            if (flag) res += abs(v[l]);
            else res += abs(v[l] * 2);
            k = l;
            l++;
            while (l < k + M && l < N && (v[k] ^ v[l]) >= 0) l++;
        }

        else {
            if (flag) res += abs(v[r]);
            else res += abs(v[r] * 2);
            k = r;
            r--;
            while (r > k - M && r >= 0 && (v[k] ^ v[r]) >= 0) r--;
        }

        flag = false;
    }

    cout << res;
    return 0;
}