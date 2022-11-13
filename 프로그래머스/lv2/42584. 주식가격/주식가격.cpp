#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> res;
    
    for(int i = 0; i < prices.size() - 1; i++){
        int x = prices[i];
        int cnt = 0;
        
        for(int j = i + 1; j < prices.size() ; j++){
            ++cnt;
            if(prices[j] < x) break;
        }
        
        res.push_back(cnt);
    }
    
    res.push_back(0);
    return res;
}