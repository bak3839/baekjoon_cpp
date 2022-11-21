#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K, sum = 0, res = -10000001;
    cin >> N >> K;
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        if (i < K) sum += v[i];
    }
    res = max(res, sum);

    for (int i = K; i < N; i++) {
        sum = sum - v[i - K] + v[i];
        res = max(res, sum);
    }

    cout << res;
    return 0;
}