#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, n;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> n;

        cout << (n * (n + 6) + 12) / 12 << "\n";
    }
    return 0;
}