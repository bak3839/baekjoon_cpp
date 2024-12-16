#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int cnt = 1;

inline bool partition(pii from, pii to, vector<string> map) {
    if(from.first == to.first) {
        if(map[from.first][from.second + 1] == 'X') return true;
    } else if(from.second == to.second) {
        if(map[from.first + 1][from.second] == 'X') return true;
    }
    else if(map[from.first][to.second] == 'X' && map[to.first][from.second] == 'X') return true;
    return false;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    vector<pii> coor;
    pii from, to;
    int dist;
    
    for(auto map : places) {
        bool pass = true;
        
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(map[i][j] == 'P') coor.push_back({i, j});
            }
        }
        
        for(int i = 0; i < coor.size(); i++) {
            from = coor[i];
            for(int j = i + 1; j < coor.size(); j++) {
                to = coor[j];
                dist = abs(from.first - to.first) + abs(from.second - to.second);
                
                if(dist == 1) {
                    pass = false;
                    break;
                }
                
                else if(dist == 2) {
                    if(!partition(from, to, map)) {
                        pass = false;
                        break;
                    }
                }
            }
            if(!pass) break;
        }
        
        if(pass) answer.push_back(1);
        else answer.push_back(0);
        cnt++;
        coor.clear();
    }
    
    return answer;
}