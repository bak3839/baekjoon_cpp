#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int total, price;

    cin >> total;

    for (int i = 0; i < 9; i++) {
        cin >> price;
        total -= price;
    }

    cout << total;
    return 0;
}