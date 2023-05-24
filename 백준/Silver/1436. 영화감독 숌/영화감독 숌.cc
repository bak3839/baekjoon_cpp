#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, cnt = 1, tmp = 667, ans;
    cin >> N;

    while (1) {
        if (N == cnt) {
            ans = tmp - 1;
            break;
        }

        if (to_string(tmp).find("666") != -1) cnt++;
        tmp++;
    }

    cout << ans;
    return 0;
}