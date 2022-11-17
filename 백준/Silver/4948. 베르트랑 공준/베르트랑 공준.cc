#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (1) {
        int n, res = 0;
        cin >> n;

        if (n == 0) break;;

        for (int i = n + 1; i <= 2 * n; i++) {
            int end = (int)sqrt(i);

            if (i == 2 || i == 3) {
                res++;
                continue;
            }

            for (int j = 2; j <= end; j++) {
                if (i % j == 0) break;
                else if (j == end && i % j != 0) res++;
            }
        }
        cout << res << "\n";
    }
    
    return 0;
}
