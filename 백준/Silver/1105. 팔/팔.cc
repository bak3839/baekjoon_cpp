#include <iostream>
#include <vector>

using namespace std;

string L, R;

void Solution() {
    int ans = 0;

    if (L.size() == R.size()) {
        for (int i = 0;i < L.size();i++) {
            if (L[i] == R[i]) {
                if (L[i] == '8') ans++;
            }
               
            else break;
        }
    }

    cout << ans;
}

void Input() {
    cin >> L >> R;
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
