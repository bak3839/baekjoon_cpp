#include <bits/stdc++.h>

using namespace std;

int N, a[15];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while (1) {
        cin >> N;

        if (N == 0) break;

        int zero = 0;

        for (int i = 0; i < N; i++) {
            cin >> a[i];
            if (a[i] == 0) zero++;
        }
            
        sort(a, a + N);

        int idx = N - 1, base1 = 1, base2 = 1, n1 = 0, n2 = 0, notZero = 0;

        if (zero == 1) swap(a[0], a[2]);
        else if (zero >= 2) {
            swap(a[0], a[zero]);
            swap(a[1], a[zero + 1]);
        }

        while (idx >= 0) {
            if (idx % 2) {
                n1 += a[idx] * base1;
   
                base1 *= 10;
            }
            else {
                n2 += a[idx] * base2;

                base2 *= 10;
            }

            idx--;
        }

        cout << n1 + n2 << "\n";
    }
    return 0;
}