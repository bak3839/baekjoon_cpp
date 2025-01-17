#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long ans = 0;
    char prev = '.';
    stack<char> s;

    string input;
    cin >> input;

    for (char ch : input) {
        if (ch == '(') s.push(ch);
        else {
            s.pop();

            if (prev == '(') ans += s.size();
        }

        prev = ch;
    }

    cout << ans;
    return 0;
}