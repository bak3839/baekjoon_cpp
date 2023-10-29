#include <vector>
#include <queue>
using namespace std;

int mv1[4] = {-1, 1, 0, 0};
int mv2[4] = {0, 0, -1, 1};

int solution(vector<vector<int> > maps){
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            // 상 하 좌 우 순서로 진행
            int nx = x + mv1[i]; 
            int ny = y + mv2[i];
            
            if((nx >= 0 && nx < maps.size()) && (ny >= 0 && ny < maps[0].size())){ // 범위가 넘어가면 무시
                if(maps[nx][ny] == 1){
                    maps[nx][ny] = maps[x][y] + 1;
                    q.push({nx, ny});
                }
            }
            
            if(nx == maps.size() - 1 && ny == maps[0].size() - 1) return maps[nx][ny];
        }
    }
    
    return -1;
}