#include <iostream>
#include <vector>

using namespace std;

int N, K;

void Solution() {
    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        if (N % i == 0) cnt++;

        if (cnt == K) {
            cout << i;
            return;
        }
    }

    cout << 0;
}

void Input() {
    cin >> N >> K;
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
