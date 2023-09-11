#include <iostream>

using namespace std;

int main() {
    int n, ans = 0;
    
    for(int i = 0; i < 5; i++) {
        cin >> n;
        ans += n;
    }
    cout << ans;
    return 0;
}