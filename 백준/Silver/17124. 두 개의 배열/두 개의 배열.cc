#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n, m, L, R, mid;
    vector<int> A, B;
    cin >> T;

    while (T--) {
        long long sum = 0;
        cin >> n >> m;

        A.resize(n);
        B.resize(m);

        for (int i = 0; i < n; i++)
            cin >> A[i];
        
        for (int i = 0; i < m; i++)
            cin >> B[i];
        sort(B.begin(), B.end());

        for (int i = 0; i < n; i++) {
            long long res = 10000000001, diff = 0, ans = 10000000001;
            L = 0; R = m - 1;

            while (L <= R) {
                mid = (L + R) / 2;
                diff = abs(A[i] - B[mid]);

                if (diff < res) {
                    res = diff;
                    ans = B[mid];
                }
                else if (diff == res) {
                    if (ans > B[mid]) ans = B[mid];
                }

                if (diff == 0) break;

                if (A[i] - B[mid] > 0) L = mid + 1;
                else R = mid - 1;
            }
            sum += ans;
        }

        cout << sum << "\n";
        A.clear();
        B.clear();
    }
    return 0;
}
