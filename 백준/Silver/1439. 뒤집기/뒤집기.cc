#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int cnt0 = 0, cnt1 = 0;
    bool same = true;
    string s;
    cin >> s;

    if (s[0] == '1') cnt1++;
    else cnt0++;

    for (int i = 1;i < s.size();i++) {
        if (s[i - 1] == s[i]) continue;
        same = false;

        if (s[i] == '1') cnt1++;
        else cnt0++;
    }

    if (same) cout << 0;
    else cout << min(cnt0, cnt1);
    return 0;
}