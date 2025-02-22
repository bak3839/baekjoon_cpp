#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int n, tmp;
    bool flag;
	cin >> n;
    
	for (int i = n; i >= 0; i--) {
		tmp = i;
		flag = true;
        
		while (tmp != 0) {
			if (tmp % 10 != 4 && tmp % 10 != 7) {
				flag = false;
				break;
			}
            
			tmp /= 10;
		}
		if (flag) {
			cout << i << "\n";
			break;
		}
	}
    
    return 0;
}