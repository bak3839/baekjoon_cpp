#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(string target, int start, vector<vector<int>> graph, vector<string> words, int size) {
    vector<bool> visit(size, false);
    int ans = 0;
    
    queue<int> q;
    q.push(start);
    visit[start] = true;
    
    while(!q.empty()) {
        int qsize = q.size();
        
        for(int k = 0; k < qsize; k++) {
            int now = q.front();
            q.pop();
        
            if(now < size && words[now] == target) return ans;
        
            for(int i=0;i<graph[now].size(); i++) {
                int next = graph[now][i];
            
                if(visit[next]) continue;
            
                q.push(next);
                visit[next] = true;
            }
        }
        
        ans++;
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<vector<int>> graph(words.size() + 1);
    
    for(int i = 0; i < words.size() + 1; i++) {
        string now;
        if(i != words.size()) now = words[i];
        else now = begin;
        
        for(int j = 0; j < words.size(); j++) {
            if(i == j) continue;
            
            string cmp = words[j];
            int cnt = 0;
            
            for(int k = 0; k < now.size(); k++){
                if(now[k] != cmp[k]) cnt++;
            }
            
            if(cnt != 1) continue;
            
            graph[i].push_back(j);
            graph[j].push_back(i);
        }
    }
    
    
    return bfs(target, words.size(), graph, words, words.size());
}