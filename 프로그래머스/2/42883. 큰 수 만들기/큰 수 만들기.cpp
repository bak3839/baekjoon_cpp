#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string ans = "";
    vector<char> res;
    res.push_back(number[0]);
    
    for(int i = 1; i < number.size(); i++) {
        while(k != 0 && res.size() != 0  && res.back() < number[i]) {
            k--;
            res.pop_back();
        }
        res.push_back(number[i]);
    }
    
    while(k != 0) {
        k--;
        res.pop_back();
    }
    
    for(int i = 0; i < res.size(); i++)
        ans.push_back(res[i]);
    
    return ans;
}