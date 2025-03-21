#include <bits/stdc++.h>

using namespace std;

int T, N, M, b;
int a[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;

        for (int i = 0; i < N; i++)
            cin >> a[i];
        sort(a, a + N);

        cin >> M;

        for (int i = 0; i < M; i++) {
            cin >> b;
            int index = lower_bound(a, a + N, b) - a;

            if (index < N && a[index] == b) cout << "1\n";
            else cout << "0\n";
        } 
    }
    return 0;
}