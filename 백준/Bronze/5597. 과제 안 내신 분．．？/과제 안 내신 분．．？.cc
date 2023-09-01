#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<bool> v(31, false);
    
    for(int i=0;i < 28; i++){
        int n;
        cin >> n;      
        v[n] = true;
    }
    
    int cnt = 0;
    for(int i = 1; i <= 30; i++){
        if(!v[i]) {
            cout << i << "\n";
            cnt++;
        }
        if(cnt == 2) break;
    }
    
    return 0;
}