#include <iostream>

using namespace std;

int main() {
    int n, min_res = 101, sum = 0;
    
    for(int i = 0; i < 7; i++) {
        cin >> n;
        if(n % 2) {
            min_res = min(min_res, n);
            sum += n;
        }
    }
    if(sum == 0) cout << -1;
    else cout << sum << "\n" << min_res;
    return 0;
}