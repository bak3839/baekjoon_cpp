#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> q;
    
    for(int i = 0; i < works.size(); i++) {
        q.push(works[i]);
    }
    
    for(int i = 0; i < n; i++) {
        if(q.empty()) break;
        
        int w = q.top() - 1;
        q.pop();
        
        if(w != 0) q.push(w);
    }
    
    while(!q.empty()) {
        int w = q.top();
        q.pop();
        
        answer += w * w;
    }
    return answer;
}