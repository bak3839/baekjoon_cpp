#include <bits/stdc++.h>
#define prev ddd
using namespace std;

int N, prev;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, min, prev = 0;
    cin >> N >> min;
    cout << 0 << " ";

    for (int i = 1; i < N; i++) {
        cin >> n;

        if (min >= n) {
            cout << prev << " ";
            min = n;
            continue;
        }

        if (n - min > prev) prev = n - min;
        cout << prev << " ";
    }

    return 0;
}