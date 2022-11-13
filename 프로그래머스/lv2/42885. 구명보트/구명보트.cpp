#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int res = 0, l = 0, r = people.size() - 1;
    sort(people.begin(), people.end());
    
    while(l < r){
        if(people[l] + people[r] <= limit) {
            ++l;
            --r;
        }
        else --r;
        ++res;
    }
    
    if(l == r) res += 1;
    return res;
}