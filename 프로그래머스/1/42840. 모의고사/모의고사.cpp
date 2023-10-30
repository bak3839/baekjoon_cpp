#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> ans;
    int p1[5] = {1, 2, 3, 4, 5};
    int p2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int p3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int n1 = 0, n2 = 0, n3 = 0;
    
    for(int i = 0; i < answers.size(); i++) {
        int now = answers[i];
        
        if(p1[i % 5] == now) n1++;
        if(p2[i % 8] == now) n2++;
        if(p3[i % 10] == now) n3++;        
    }
    int res = max(n1, max(n2, n3));
    
    if(n1 == res) ans.push_back(1);
    if(n2 == res) ans.push_back(2);
    if(n3 == res) ans.push_back(3);
    return ans;
}