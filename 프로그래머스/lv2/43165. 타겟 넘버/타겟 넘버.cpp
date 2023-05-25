#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int ans = 0, index = 0;
    queue<int> q;
    q.push(0);
    
    while(index < numbers.size()){
        int size = q.size();
        
        for(int i=0; i<size; i++){
            int now = q.front();
            q.pop();
            
            q.push(now + numbers[index]);
            q.push(now - numbers[index]);
        }
        index++;
    }
    
    while(!q.empty()){
        if(q.front() == target) ans++;
        q.pop();
    }
    
    return ans;
}