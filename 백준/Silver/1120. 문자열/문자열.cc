#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int ans = 51;
    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; s1.size() + i <= s2.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < s1.size(); j++) {
            if (s1[j] != s2[j + i]) ++cnt;
        }

        ans = min(cnt, ans);
        if (ans == 0) break;
    }
    
    cout << ans;
    return 0;
}