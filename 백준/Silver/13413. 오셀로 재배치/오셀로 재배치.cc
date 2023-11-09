#include <iostream>
#include <vector>

using namespace std;

int N;
string origin, target;

int Solution() {
    int ans = 0, OB = 0, TB = 0;

    for (int i = 0; i < N; i++) {
        if (origin[i] == target[i]) continue;

        if (origin[i] == 'B') OB++;
        else TB++;
    }

    return max(TB, OB);
}

void Input() {
    cin >> N >> origin >> target;
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        cout << Solution() << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}