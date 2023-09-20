#include <iostream>

using namespace std;

int main() {
    int n, k, ans = 0;
    
    cin >> n;
    n %= 10;
    
    for(int i = 0; i < 5; i++) {
        cin >> k;
        if(k == n) ans++;
    }
    cout << ans;
    return 0;
}