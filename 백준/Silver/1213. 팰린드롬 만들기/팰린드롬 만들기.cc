#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    vector<char> v, ans;
    cin >> S;
    
    for (char ch : S) {
        v.push_back(ch);
    }

    ans.resize(S.size(), '*');
    sort(v.begin(), v.end());

    int L = 0, R = S.size() - 1, i = 0;

    while (L < R) {
        int idx1 = i;
        int idx2 = i + 1;

        if (v[i] == v[i + 1]) {
            ans[L++] = v[i];
            ans[R--] = v[i + 1];
            i += 2;
        }
        else {
            if (S.size() % 2 == 0 || ans[S.size() / 2] != '*') {
                cout << "I'm Sorry Hansoo";
                return 0;
            }

            ans[S.size() / 2] = v[i];
            i++;
        }
    }

    if (i == S.size() - 1) {
        ans[L] = v[i];
    }

    for (char ch : ans)
        cout << ch;
    return 0;
}
