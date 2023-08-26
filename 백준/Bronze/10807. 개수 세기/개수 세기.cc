#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, T, cnt = 0;
	cin >> N;
    
    vector<int> v(N);
    
    for(int i = 0; i < N; i++) 
        cin >> v[i];
    
    cin >> T;
    
    for(int i = 0; i < N; i++) {
        if(v[i] == T) cnt++;
    }
    cout << cnt;
	
	return 0;
}