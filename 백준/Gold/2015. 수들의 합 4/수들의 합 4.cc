#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<ll> sum(N + 1);
    map<ll, ll> m;
    sum[0] = 0;

    ll res = 0;
    for (int i = 1; i <= N; i++) {
        cin >> sum[i];
        if (i > 1) sum[i] += sum[i - 1];
        
    }

    for (int i = 1; i <= N; i++) {
        if (sum[i] == K) ++res;
        res += m[sum[i] - K];
        m[sum[i]]++;
    }

    cout << res;
    return 0;
}