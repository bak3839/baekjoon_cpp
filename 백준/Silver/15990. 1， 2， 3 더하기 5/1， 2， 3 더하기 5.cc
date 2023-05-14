#include <iostream>
#include <vector>

using namespace std;

int N, pre = 3;
int DP[100001][4];

void Solution(int n) {
    int ans = 0;

    if (pre < n) {  
        for (int i = pre + 1; i <= n; i++) {
            DP[i][1] = (DP[i - 1][2] + DP[i - 1][3]) % 1000000009;
            DP[i][2] = (DP[i - 2][1] + DP[i - 2][3]) % 1000000009;
            DP[i][3] = (DP[i - 3][1] + DP[i - 3][2]) % 1000000009;
        }
        pre = n;
    }

    for (int i = 1; i <= 3; i++) {
        ans = (ans + DP[n][i]) % 1000000009;
    }
   
    cout << ans << "\n";
}

void Input() {
    int n;
    cin >> N;

    DP[1][1] = 1; DP[2][2] = 1;
    DP[3][1] = 1; DP[3][2] = 1; DP[3][3] = 1;

    for (int i = 0; i < N; i++) {
        cin >> n;
        Solution(n);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    return 0;
}