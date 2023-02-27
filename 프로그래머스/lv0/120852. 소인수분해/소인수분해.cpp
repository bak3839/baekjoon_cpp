#include <string>
#include <vector>

using namespace std;
bool visit[9999];

vector<int> solution(int n) {
    vector<int> ans;
    
    int i = 2;
    
    if (n == 2) ans.push_back(i);
    
	while (i < n) {
		if (n % i == 0) {
			if(!visit[i]) ans.push_back(i);
            visit[i] = true;
			n /= i;
		}
		else i++;
        
		if (i == n) {
			if(!visit[i]) ans.push_back(i);
            visit[i] = true;
			break;
		}
	}
    return ans;
}