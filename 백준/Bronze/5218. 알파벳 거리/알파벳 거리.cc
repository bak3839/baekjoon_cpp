#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        string x, y;
        cin >> x >> y;
        cout << "Distances: ";
        
        for(int j = 0; j < x.length(); j++){
            int X = x[j] - 'A';
            int Y = y[j] - 'A';
            
            if(Y - X >= 0) cout << Y - X << " ";
            else cout << Y - X + 26 << " ";
        }
        cout << "\n";
    }
    return 0;
}