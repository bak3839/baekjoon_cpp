#include <string>
#include <vector>

using namespace std;

int ans, limit;
vector<bool> visit;

void Search(int k, vector<vector<int>> d, int cnt, int done){
    if(cnt == limit) {
        ans = max(ans, done);
        return;
    }
    
    for(int i=0; i < d.size(); i++){
        if(visit[i]) continue;
        
        int need = d[i][0];
        int fati = d[i][1];
        
        visit[i] = true;
        if(need > k) Search(k, d, cnt + 1, done);
        else if(k - fati < 0) Search(k, d, cnt + 1, done);
        else Search(k - fati, d, cnt + 1, done + 1);
        visit[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    limit = dungeons.size();
    visit.resize(limit);
    
    Search(k, dungeons, 0, 0);
    
    return ans;
}