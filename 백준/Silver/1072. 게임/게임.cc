#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Z, L, R, mid, ans = 1000000001, g, res;
    double X, Y;
    cin >> X >> Y;
    Z = (Y * 100 / X);

    L = 0;
    R = 1000000000;

    while (L <= R) {
        // 추가 게임 회수
        mid = (L + R) / 2;
        res = ((double)(Y + mid) / (double)(X + mid)) * 100;

        if (Z < res) {
            ans = min(ans, mid);
            R = mid - 1;
        }
        else L = mid + 1;
    }
    
    if (ans == 1000000001) cout << -1;
    else cout << ans;
    return 0;
}
