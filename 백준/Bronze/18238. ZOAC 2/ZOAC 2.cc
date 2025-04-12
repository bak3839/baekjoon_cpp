#include <bits/stdc++.h>

using namespace std;

string str;
int now, ans;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    cin >> str;
    
    for(int i=0; i<str.length(); i++){
        int next = str[i] - 'A';
        int dist1 = abs(now - next);
        int dist2 = 26 - dist1;
        
        if(dist1 < dist2) ans += dist1;
        else ans += dist2;
        
        now = next;
    }
    
    cout << ans;
    return 0;
}