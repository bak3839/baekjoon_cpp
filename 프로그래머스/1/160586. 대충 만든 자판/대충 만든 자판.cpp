#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> ans;
    vector<int> count(26, -1);
     
    for(int i = 0; i < keymap.size(); i++) {
        string key = keymap[i];
        
        for(int j = 0; j < key.size(); j++) {
            int num = count[key[j] - 'A'];
            
            if(num == -1) count[key[j] - 'A'] = j + 1;
            else count[key[j] - 'A'] = min(num, j + 1);
        }
    }
    
    for(int i = 0; i < targets.size(); i++) {
        int sum = 0;
        string target = targets[i];
        
        for(int j = 0; j < target.size(); j++) {
            if(count[target[j] - 'A'] == -1) {
                sum = -1;
                ans.push_back(-1);
                break;
            }
            
            sum += count[target[j] - 'A'];
        }
        
        if(sum != -1) ans.push_back(sum);
    }
    
    return ans;
}