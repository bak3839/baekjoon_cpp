#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int ans = 0;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') ans++;
    }
    cout << ans + 1;
    return 0;
}