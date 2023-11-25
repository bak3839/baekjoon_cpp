#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int ans = 0, N, coin;
    cin >> N;

    for (int i = 0;i < 2;i++)
        for (int j = 0;j < N;j++) {
            cin >> coin;
            ans += abs(coin);
        }

    cout << ans;
    return 0;
}
