#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
	int n; cin >> n;
	vector <int> v(n); 
    
	for (int i = 0; i < n; i++) cin >> v[i]; 
    
	int b, c;
	cin >> b >> c; 
    
	long long result = n ; 
	for (int i = 0; i < n; i++) {
		v[i] -= b;
		if (v[i] <= 0) continue; 
        
		result += v[i] / c; 
        
		if (v[i] % c)result += 1; 
	}
    
	cout << result; 
    return 0;
}