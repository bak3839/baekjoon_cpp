#include <bits/stdc++.h>

using namespace std;

int N, number;
int check[200001];

void solve(){
    int ans = 0;
    
    for(int i = 1 ; i <= N; i++){
        int x, y;
        cin >> x >> y;
        
        number = max(number, x);
        
        if(y == 0){
            if(check[x] == 1) check[x] = 0;
            else ans++;
        }
        else{
            if(check[x] == 1) ans++;
            else check[x] = 1;
        }
    }
    
    for(int i = 1; i <= number; i++){
        if(check[i] != 0) ans++;
    }
    
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> N;
	solve();
	return 0;
}