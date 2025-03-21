#include <bits/stdc++.h>

using namespace std;

int n, cnt, ans, res[200001];
string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> s, tmp;
    cin >> n >> str;

    for (int i = 0; i < n; i++) {
        if (str[i] == '(') s.push(i);
        else if (!s.empty()) {
            res[i] = res[s.top()] = 1;
            s.pop();
        }
    }

    for (int i = 0; i < n; i++) {
        if (res[i] == 1) cnt++;
        else {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    ans = max(ans, cnt);
    cout << ans;
    return 0;
}