#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q, prev, now, s, e;
    cin >> N >> Q;

    vector<int> a(N + 1, 0);

    cin >> prev;

    for (int i = 2; i <= N; i++) {
        cin >> now;

        a[i] = a[i - 1] + abs(now - prev);
        prev = now;
    }

    for (int i = 0; i < Q; i++) {
        cin >> s >> e;
        cout << a[e] - a[s] << "\n";
    }
    
    return 0;
}