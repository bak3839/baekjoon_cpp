#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int res[10] = { 0, 1, 3, 6, 10, 15, 21,28,36,45 };
    int n;

    cin >> n;

    cout << res[n - 1];

    return 0;
}