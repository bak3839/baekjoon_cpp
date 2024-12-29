#include <bits/stdc++.h>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = enemy.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    
    if(enemy.size() <= k) return enemy.size();
    
    for(int i = 0; i < enemy.size(); i++) {
        pq.push(enemy[i]);
        
        if(pq.size() > k) {
            n -= pq.top();
            pq.pop();
            
            if(n < 0) {
                answer = i;
                break;
            }
        }
    }
    
    
    return answer;
}