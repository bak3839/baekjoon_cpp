#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

int isPallindrome(string s) {
    int l = 0, r = s.size() - 1;

    while (l < r) {
        cnt++;

        if (s[l++] != s[r--]) return 0;  
    }
    
    cnt++;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string s;

    for (int i = 0; i < N; i++) {
        cin >> s;

        cout << isPallindrome(s) << " " << cnt << "\n";
        cnt = 0;
    }
    return 0;
}
