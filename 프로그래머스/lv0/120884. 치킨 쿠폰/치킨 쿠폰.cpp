#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int rest = 0, ans = 0;
    
    while(chicken >= 10){        
        rest += chicken % 10;
        chicken /= 10;
        ans += chicken;
    }
    
    rest += chicken;
    
    while(rest >= 10) {
        ans += rest / 10;
        rest = rest / 10 + rest % 10;
    }
    
    return ans;
}