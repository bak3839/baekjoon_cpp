#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, T, l, v;
    cin >> N >> T;

    stack<long long> s;

    for (int i = 0; i < N; i++) {
        cin >> l >> v;

        s.push(1LL * T * v + l);
    }

    long long prev = s.top();
    s.pop();

    while (!s.empty()) {
        if (s.top() >= prev) N--;
        else prev = s.top();
        s.pop();
    }

    cout << N;
    return 0;
}