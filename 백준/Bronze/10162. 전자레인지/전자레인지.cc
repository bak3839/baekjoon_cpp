#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    vector<int> time(3, 0);
    vector<int> ans(3, 0);
    time[0] = 300; time[1] = 60; time[2] = 10;
    
    cin >> T;
    
    for(int i = 0; i < 3; i++){
        ans[i] = T / time[i];
        T %= time[i];
    }
    
    if(T != 0) cout << "-1";
    else {
        for(int i = 0; i < 3; i++) {
            cout << ans[i] << " ";
        }
    }
    
    return 0;
}