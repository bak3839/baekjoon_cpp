#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, L, R;

void Solution() {
    int g[7] = { 1, 2, 5, 10, 20, 50, 100 };
    int target = abs(L - R);

    if (target == 0) {
        cout << 0;
        return;
    }

    vector<int> DP(target + 1, 2100000000);
    DP[0] = 0;    

    for (int i = 0; i < 7; i++) {
        if (target < g[i]) break;

        for (int j = g[i]; j <= target; j++) {
            DP[j] = min(DP[j], DP[j - g[i]] + 1);
        }
    }

    cout << DP[target];
}

void Input() {
    int s;
    cin >> N;

    for (int i = 0;i < N;i++) {
        cin >> s;

        if (i == 0) L += s;
        else if (i == 1) R += s;
        else if (L == R) L += s;
        else {
            if (L < R) L += s;
            else R += s;
        }
    }       
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}
