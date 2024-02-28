#include <iostream>
#include <bitset>

using namespace std;

int N;

void Solution() {
    int ans = 0;
    string num = bitset<8>(N).to_string();

    for (int i = 0; i < num.size(); i++) {
        if (num[i] == '1') ans++;
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
