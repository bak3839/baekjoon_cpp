#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, ans;
char n[3] = { '0', '1', '2' };

void Search(string res, int x, int cnt) {
    if (cnt == 0) {
        if (stoi(res) % 3 == 0) ans++;
        return;
    }

    for (int i = x; i < 3; i++) 
        Search(res + n[i], 0, cnt - 1);
}

void Solution() {
    Search("", 1, N);
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
