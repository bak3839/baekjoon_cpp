#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) {
    if(N > M) {
        int tmp = N;
        N = M;
        M = tmp;
    }
    
    return M * (N - 1) + (M - 1);
}