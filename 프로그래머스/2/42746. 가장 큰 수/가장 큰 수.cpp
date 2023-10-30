#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string n1, string n2) {
    return n1 + n2 > n2 + n1;
}

string solution(vector<int> numbers) {
    string ans = "";
    vector<string> snum;
    
    for(auto n : numbers) snum.push_back(to_string(n));
    
    sort(snum.begin(), snum.end(), compare);
    
    if(snum[0] == "0") return "0";
    
    for(auto n : snum) ans += n;
    return ans;
}