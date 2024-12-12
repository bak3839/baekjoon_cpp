#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

bool compare(vector<int> v1, vector<int> v2) {
    return v1.size() < v2.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> tmp;
    vector<bool> checked(100001, false);
    vector<vector<int>> total;
    
    
    string set, num;
    stringstream ss(s);
    
    while(getline(ss, set, '}')) {
        if(set == "}") break;
        
        set.erase(0, 2);
        stringstream ss2(set);
        
        while(getline(ss2, num, ',')) {
            tmp.push_back(stoi(num));
        }
        total.push_back(tmp);
        tmp.clear();
    }
    
    sort(total.begin(), total.end(), compare);
    
    for(auto nums : total) {
        for(auto n : nums) {
            if(checked[n]) continue;
            
            checked[n] = true;
            answer.push_back(n);
        }       
    }
    
    return answer;
}