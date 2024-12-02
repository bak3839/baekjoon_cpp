#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 10;
    string dish;
    cin >> dish;

    for (int i = 1; i < dish.size(); i++) {
        if (dish[i - 1] != dish[i]) ans += 10;
        else ans += 5;
    }

    cout << ans;

    return 0;
}