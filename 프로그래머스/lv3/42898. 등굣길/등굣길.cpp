#include <string>
#include <vector>

using namespace std;
using ll = long long;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<ll>> map(n + 1, vector<ll>(m + 1, 0));
    map[1][1] = 1;
    
    for(int i = 0; i < puddles.size(); i++){
        int y = puddles[i][0];
        int x = puddles[i][1];
        map[x][y] = -1;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if((i == 1 && j == 1) || map[i][j] == -1) continue;
            
            ll up = map[i - 1][j] != -1 ? map[i - 1][j] : 0;
            ll left = map[i][j - 1] != -1 ? map[i][j - 1] : 0;
            
            map[i][j] =  (up + left) % 1000000007; 
        }
    }
    
    return map[n][m];
}