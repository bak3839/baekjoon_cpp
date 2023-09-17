#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b, ans = 0, total = 0;

    for (int i = 0; i < 4; i++) {
        cin >> a >> b;

        total = total - a + b;
        ans = max(ans, total);
    }
    cout << ans;
    return 0;
}
