#include <iostream>
#include <algorithm>

using namespace std;

int a, n,ans;

int main() {
    
    cin >> n;
    int *group = new int[n+1];
    
    for (int i = 1; i <= n; i++) {
        cin >> group[i];
    }
    
    for (int r = n-3; r >=1; r--) {
        int itmp = 1;
        
        for (int i = 1; i <= r; i++) {
            
            int jtmp = 1;
            itmp *= group[i];
            for (int j = i+1; j <= n - 2; j++) {
                jtmp *= group[j];
                int ktmp = 1;
                
                for (int k = j+1; k <= n - 1; k++){
                    ktmp *= group[k];
                    int ftmp = 1;
                    
                    for (int f = k+1; f <= n; f++){
                        ftmp *= group[f];
                    }
                    
                    ans = max(ans, itmp + jtmp + ktmp + ftmp);
                }
            }
        }
    }
    
    cout << ans;
    return 0;
}