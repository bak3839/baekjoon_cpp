#include <bits/stdc++.h>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0, cnt = 0;
    vector<pair<int, string>> v;
    set<string> cache;
    
    for(string city : cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        
        if(cache.find(city) == cache.end()) {
            if(cacheSize == 0) {
                answer += 5;
                continue;
            }

            if(v.size() >= cacheSize) {
                sort(v.begin(), v.end());
                cache.erase(v[0].second);               
                v[0] = {cnt, city};             
            } else {     
                v.push_back({cnt, city});
            }
            
            cache.insert(city);    
            answer += 5;            
        }
        else {
            for(int i = 0; i < v.size(); i++) {
                if(v[i].second == city) {
                    v[i] = {cnt, city};
                    break;
                }
            }
            answer += 1;
        }
        cnt++;
    }
    
    return answer;
}