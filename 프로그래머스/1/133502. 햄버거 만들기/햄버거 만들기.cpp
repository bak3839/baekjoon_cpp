#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient) {
    vector<int> v;
    int ans = 0;
    
    for(int i = 0; i < ingredient.size(); i++) {
        int n = ingredient[i], size;
        
        v.push_back(n);
        size = v.size();
        
        if(size >= 4) {

            if(v[size - 4] == 1 && v[size - 3] == 2 && v[size - 2] == 3 && v[size - 1] == 1) {
                ans++;
                
                for(int j = 0; j < 4; j++) v.erase(v.begin() + size - 4);
            }
        } 
    }

    return ans;
}