#include <bits/stdc++.h>

using namespace std;

int A, B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<string> ans;
    cin >> A >> B;

    while (A >= 2 && B >= 1) {
        if (A == B + 1) {
            string tmp = "";
            for (int i = 0; i < A + B; i++) {
                if (i % 2) tmp.push_back('b');
                else tmp.push_back('a');
            }
            
            A = 0, B = 0;
            ans.push_back(tmp);
            break;
        }

        A -= 2;
        B -= 1;
        ans.push_back("aba");
    }
    
    if (A == 0 && B == 0) {
        cout << "YES\n";
        cout << ans.size() << "\n";
        for (string s : ans)
            cout << s << "\n";
    }
    else {
        cout << "NO";
    }
    return 0;
}