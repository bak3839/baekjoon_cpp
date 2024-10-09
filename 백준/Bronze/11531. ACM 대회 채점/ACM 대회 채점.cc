#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, ans = 0, cnt = 0;
    char ch;
    string res;
    map<char, int> m;

    while (1) {
        cin >> n;

        if (n == -1) break;

        cin >> ch >> res;

        if (res == "wrong") m[ch]++;
        else {
            cnt++;
            ans += (n + m[ch] * 20);
        }
        
    }

    cout << cnt << " " << ans;
    return 0;
}