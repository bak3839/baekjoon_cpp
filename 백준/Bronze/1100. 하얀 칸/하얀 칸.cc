#include <iostream>
#include <vector>

using namespace std;


void Solution() {
    string s;
    int j, ans = 0;

    for (int i = 0;i < 8;i++) {
        cin >> s;

        if (i % 2) j = 1;
        else j = 0;

        for (; j < 8; j += 2) {
            if (s[j] == 'F') ans++;
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solution();
    return 0;
}