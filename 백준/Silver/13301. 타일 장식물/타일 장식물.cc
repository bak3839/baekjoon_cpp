#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<ll> v(N + 1);
    v[0] = 0;
    v[1] = 1;

    for (int i = 2; i <= N; i++) v[i] = v[i - 1] + v[i - 2];

    cout << v[N] * 2 + (v[N] + v[N - 1]) * 2;

    return 0;
}