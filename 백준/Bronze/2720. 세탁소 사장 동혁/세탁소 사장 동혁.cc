#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    int base[4] = { 25, 10, 5, 1 };

    for (int i = 0;i < N;i++) {
        int rest;
        cin >> rest;

        for (int j = 0;j < 4;j++) {
            cout << rest / base[j] << " ";
            rest %= base[j];
        }
        cout << "\n";
    }
    return 0;
}