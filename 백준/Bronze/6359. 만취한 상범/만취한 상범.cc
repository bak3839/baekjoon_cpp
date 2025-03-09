#include <bits/stdc++.h>

using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T, n;
    cin >> T;
    
    while (T--) {
        cin >> n;
        cout << int(sqrt(n)) << '\n';
    }
 
    return 0;
}