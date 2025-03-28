#include <bits/stdc++.h>

using namespace std;

int N, K, A[100001], sum, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i < K) sum += A[i];
    }
    
    ans = sum;
    int L = 0, R = K - 1;

    while (L < N) {
        sum -= A[L++];
        sum += A[(++R) % N];

        ans = max(ans, sum);
    }

    cout << ans;
    return 0;
}