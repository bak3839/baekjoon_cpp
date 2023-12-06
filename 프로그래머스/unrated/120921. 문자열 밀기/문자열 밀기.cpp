#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int ans = 0, i = 0;
    
    for(i = 0; i < A.size(); i++) {
        if(A == B) break;
        
        A = A[A.size() - 1] + A;
        A.pop_back();
        ans++;
    }
    
    if(A.size() == i) ans = -1;
    return ans;
}