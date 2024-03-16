#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<int> DP(n + 1, 0);
    DP[0] = 1;
    DP[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        DP[i] = (DP[i - 1] + DP[i - 2]) % 1234567;
    }
    answer = DP[n];
    
    return answer;
}