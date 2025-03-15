#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> fibo(46);
    fibo[0] = 0;
    fibo[1] = 1;

    for (int i = 2; i <= 45; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    int T, n, index;
    cin >> T;

    while (T--) {
        cin >> n;
        index = upper_bound(fibo.begin(), fibo.end(), n) - fibo.begin();

        stack<int> s;
        
        for (int i = index - 1; i > 0; i--) {
            if (n - fibo[i] >= 0) {
                n -= fibo[i];
                s.push(fibo[i]);
            }
            
            if (n == 0) break;
        }
        
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << "\n";
    }
    return 0;
}
