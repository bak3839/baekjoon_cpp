#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    set<ll> S;
    S.insert(0);

    ll prev = 0;

    for (int i = 1; i <= N; i++) {
        ll res = prev - i;

        if (res < 0 || S.find(res) != S.end())
            res = prev + i;

        S.insert(res);
        prev = res;
    }

    cout << prev;
    
    return 0;
}