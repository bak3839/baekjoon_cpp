#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int rest = s % n, share = s / n;
    
    if(share == 0) {
        answer.push_back(-1);
    } else {
        for(int i = 0; i < n; i++) {
            answer.push_back(share);
        }
        
        int index = n - 1;
        
        while(rest > 0) {
            answer[index]++;
            index--;
            rest--;
            
            if(index < 0) index = n - 1;
        }
    }
    return answer;
}