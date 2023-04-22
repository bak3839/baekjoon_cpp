#include <iostream>
#include <vector>

using namespace std;
void Solution() {
    int N, a, b, ans = 0;
    cin >> N >> a >> b;

    while (a != b) {
        ans++;
        a = a / 2 + a % 2;
        b = b / 2 + b % 2;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Solution(); 
    return 0;
}