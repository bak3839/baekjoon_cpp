#include <bits/stdc++.h>

using namespace std;

int N, S, R;
bool broken[11], remain[11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> N >> S >> R;

    for (int i = 0; i < S; i++) {
        cin >> n;
        broken[n] = true;
    }

    for (int i = 0; i < R; i++) {
        cin >> n;
        remain[n] = true;
    }

    for (int i = 1; i <= N; i++) {
        if (broken[i] && remain[i]) {
            S--;
            broken[i] = false;
            remain[i] = false;
        }
        else if (i != 1 && remain[i] && broken[i - 1]) {
            S--;
            broken[i - 1] = false;
            remain[i] = false;
        }
        else if (i != N && remain[i] && broken[i + 1] && !remain[i + 1]) {
            S--;
            broken[i + 1] = false;
            remain[i] = false;
        }
    }
    
    cout << S;
    return 0;
}