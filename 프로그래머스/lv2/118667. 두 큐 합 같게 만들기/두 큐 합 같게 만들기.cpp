#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int cnt = 0;
    long long sum1 = 0, sum2 = 0, target;
    int size1 = queue1.size(), size2 = queue2.size(), idx1 = 0, idx2 = 0, max_cnt = size1 + size2;
    
    for(int i = 0; i < queue1.size(); i++) {
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    
    target = (sum1 + sum2) / 2;
    
    while(sum1 != target){
        if((size1 <= idx1 || size2 <= idx2) || max_cnt + 2 < cnt) {
            cnt = -1;
            break;
        }
        
        if(sum1 > target){
            sum1 -= queue1[idx1];
            sum2 += queue1[idx1];
            queue2.push_back(queue1[idx1++]);
            size2++;
        }
        
        else if(sum1 < target){
            sum1 += queue2[idx2];
            sum2 -= queue2[idx2];
            queue1.push_back(queue2[idx2++]);
            size1++;
        }
        
        ++cnt;
    }
    
    return cnt;
}