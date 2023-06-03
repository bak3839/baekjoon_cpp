#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int sum = 0, now, ans = 0;

    for (int i = 0; i < 10; i++) {
        cin >> now;
        sum += now;

        if (abs(ans - 100) >= abs(sum - 100))
            ans = sum;
    }
    
    cout << ans;
    return 0;
}