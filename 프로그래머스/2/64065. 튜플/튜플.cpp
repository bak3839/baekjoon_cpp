#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

bool compare(pii p1, pii p2) {
    return p1.second > p2.second;
}

vector<int> solution(string s) {
    map<int, int> m;
    vector<int> answer;    
    vector<vector<int>> total;   
    
    string set, num;
    stringstream ss(s);
    
    while(getline(ss, set, '}')) {
        if(set == "}") break;
        
        set.erase(0, 2);
        stringstream ss2(set);
        
        while(getline(ss2, num, ',')) {
            int n = stoi(num);
            m[n]++;
        }
    }
    
    vector<pii> res(m.begin(), m.end());
    sort(res.begin(), res.end(), compare);
    
    for(auto p : res) {
        answer.push_back(p.first);
    }
    
    return answer;
}