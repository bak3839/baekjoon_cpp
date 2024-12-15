#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int mv[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int keypad[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 0, 11}};

int getDist(int r, int c, int target) {
    if(keypad[r][c] == target) return 0;
    
    int x, y, nx, ny, size, dist = 0;
    vector<bool> visited(12, false);
    
    queue<pii> q;
    q.push({r, c});
    visited[keypad[r][c]] = true;
    
    while(!q.empty()) {
        size = q.size();
        
        while(size--) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
        
            for(int i = 0; i < 4; i++) {
                nx = x + mv[i][0];
                ny = y + mv[i][1];
            
                if(nx < 0 || ny < 0 || nx > 3 || ny > 2 || visited[keypad[nx][ny]]) continue;
                if(keypad[nx][ny] == target) return dist + 1;
                
                q.push({nx, ny});
                visited[keypad[nx][ny]] = true;
            }
        }
        dist++;
    }
    return dist;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<pii> coor(10);    
    int index = 1, x, y;
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            coor[index].first = i;
            coor[index].second = j;
            index++;
        }
    }
    coor[0].first = 3, coor[0].second = 1;
    
    pii L = make_pair(3, 0);
    pii R = make_pair(3, 2);
    
    for(int n : numbers) {
        x = coor[n].first, y = coor[n].second;
        
        if(n == 1 || n == 4 || n == 7) {
            answer.push_back('L');
            L.first = x;
            L.second = y;
        }
        
        else if(n == 3 || n == 6 || n == 9) {
            answer.push_back('R');
            R.first = x;
            R.second = y; 
        }
        
        else {
            int distL = getDist(L.first, L.second, n);
            int distR = getDist(R.first, R.second, n);
        
            if(distL < distR || (distL == distR && hand == "left")) {
                answer.push_back('L');
                L.first = x;
                L.second = y;
            } 
            else if(distL > distR || (distL == distR && hand == "right")) {
                answer.push_back('R');
                R.first = x;
                R.second = y;
            }
        }
        
    }
    return answer;
}