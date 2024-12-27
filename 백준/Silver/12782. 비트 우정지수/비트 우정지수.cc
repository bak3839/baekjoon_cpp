#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string s1, s2;

void Solution() {
    int a = 0, b = 0;

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '1' && s2[i] == '0') a++;
        else if (s1[i] == '0' && s2[i] == '1') b++;
    }

    cout << (min(a, b) + abs(a - b)) << "\n";
}

void Input() {
    cin >> s1 >> s2;
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}