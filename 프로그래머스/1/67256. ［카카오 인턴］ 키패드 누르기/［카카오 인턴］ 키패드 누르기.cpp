#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

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
            int distL = abs(L.first - x) + abs(L.second - y);
            int distR = abs(R.first - x) + abs(R.second - y);
        
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