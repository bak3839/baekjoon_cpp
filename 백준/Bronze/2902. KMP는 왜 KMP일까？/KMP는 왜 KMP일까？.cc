#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s, ans;
    cin >> s;
    ans.push_back(s[0]);

    for (int i = 1;i < s.size();i++) {
        if (s[i] == '-') ans.push_back(s[i + 1]);
    }
    cout << ans;
    return 0;
}