#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, a, b, p1 = 100, p2 = 100;
    cin >> N;

    while (N--) {
        cin >> a >> b;

        if (a == b) continue;
        else if (a < b) p1 -= b;
        else p2 -= a;
    }

    cout << p1 << "\n" << p2;
    return 0;
}