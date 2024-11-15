#include <iostream>

using namespace std;

int main(){
    int a = 0, b = 0, t;
    
    for (int i = 0; i < 4; i++){
        cin >> t;
        a += t;
    }
    
    for (int i = 0; i < 4; i++){
        cin >> t;
        b += t;
    }
    
    cout << max(a,b);
    
    return 0;
}