#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> res(id_list.size(), 0);

    vector<vector<int>> over(id_list.size(),vector <int>(id_list.size(),1));
    
    map<string, pair<int, int>> m;
    
    for(int i = 0; i < id_list.size(); i++){ // first = 유저번호 second = 신고회수
        m.insert({id_list[i], make_pair(i, 0)});
    }
    
    string dec = ""; // 신고 당한 사람
    string per = ""; // 신고 한 사람
    
    for(int j = 0; j < report.size(); j++) { // 신고내역 파싱
        string rp = report[j];
        dec = "";
        per = "";
        
        int i = 0;
        for(i = 0; rp[i] != ' '; i++){
            per += rp[i];
        }
        dec = rp.substr(i + 1);
        pair<int, int> p1 = m[dec]; // 신고 당한 사람
        
        pair<int, int> p2 = m[per]; // 신고 한 사람
        
        if(over[p1.first][p2.first] != 1) continue;
        
        over[p1.first][p2.first] = 0;
        m[dec].second++;   
    }

    for(int i = 0; i < id_list.size(); i++){
        int user = m[id_list[i]].first; // 유저번호
        int n = m[id_list[i]].second; // 신고회수
        
        if(n >= k){
            for(int j = 0; j < id_list.size(); j++){
                if(over[user][j] == 0) res[j]++;
            }
        }
    }
    
    return res;
}