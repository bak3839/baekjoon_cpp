#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;

void Solution() {
    int ans = 0;
    
    for (int i = 5; i <= N; i *= 5) {
        ans += N / i;
    }

    cout << ans;
}

void Input() {
    cin >> N;
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
