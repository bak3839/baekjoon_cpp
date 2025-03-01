#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a1, a0, n, c;
    cin >> a1 >> a0;
    cin >> c;
    cin >> n;
 
    if (a1 * n + a0 <= c * n && a1 <= c)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
 
    return 0;
}
