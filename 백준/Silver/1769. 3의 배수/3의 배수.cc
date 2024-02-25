#include <iostream>
#include <vector>
#include <string>

using namespace std;

string num;

void Solution() {
    int ans = 0;

    while (num.size() > 1) {
        int sum = 0;

        for (int i = 0; i < num.size(); i++) 
            sum += num[i] - '0';

        num = to_string(sum);
        ans++;
    }

    cout << ans << "\n";
    if ((num[0] - '0') % 3) cout << "NO";
    else cout << "YES";
}

void Input() {
    cin >> num;
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
