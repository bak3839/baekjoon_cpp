#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, res;
    cin >> N;

    vector<int> sum(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> sum[i];
        if (i > 2) sum[i] += sum[i - 2];   
    }

    res = max(sum[N], sum[N - 1]);

    for (int i = 2; i <= N; i++) {
        int tmp;
        if (i % 2) tmp = sum[i - 2] + sum[N] - sum[i - 1];
        else tmp = sum[i - 1] + sum[N - 2] - sum[i - 2];
        res = max(res, tmp);
    }

    cout << res;
    return 0;
}