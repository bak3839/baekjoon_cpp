#include <bits/stdc++.h>

using namespace std;

int N, ans;
bool A[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> n;
        if (n) A[i] = true;
    }

    for (int i = 0; i < N; i++) {
        if (A[i]) {
            ans++;

            for (int j = i; j <= i + 2; j++) {
                A[j] = (A[j] ? false : true);
            }
        }
    }
    
    cout << ans;
    return 0;
}