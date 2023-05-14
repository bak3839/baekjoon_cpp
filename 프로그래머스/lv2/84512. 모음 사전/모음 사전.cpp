#include <string>
#include <vector>

using namespace std;

int ans, cnt;
char ch[5] = {'A', 'E', 'I', 'O', 'U'};

void search(string tmp, string word){    
    if(tmp == word) {
        ans = cnt;
        return;
    }
    
    cnt++;
    
    if(tmp.size() >= 5 || ans != 0) return;     
    
    for(int i = 0; i < 5; i++){
        tmp.push_back(ch[i]);
        search(tmp, word);
        tmp.pop_back();
        if(ans != 0) return;
    }
}

int solution(string word) {
    search("", word);
    return ans;
}