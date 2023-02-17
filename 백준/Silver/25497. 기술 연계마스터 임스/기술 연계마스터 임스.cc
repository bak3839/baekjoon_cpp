#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    int N, ans = 0;
    int cnt[2] = { 0, 0 };
    cin >> N >> s;

    for (int i = 0; i < N; i++) {
        if (s[i] == 'L') cnt[0]++;
        else if (s[i] == 'S') cnt[1]++;
        else if (s[i] == 'R') {
            if (cnt[0] <= 0) break;
            ans++;
            cnt[0]--;
        }
        else if (s[i] == 'K') {
            if (cnt[1] <= 0) break;
            ans++;
            cnt[1]--;
        }
        else ans++;
    }

    cout << ans;
    return 0;
}