#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1, s2, s3, s4; 
	cin >> s1 >> s2 >> s3 >> s4;
    
	string res1 = s1 + s2; 
	string res2 = s3 + s4;
    
	long long ans = stoll(res1) + stoll(res2);
	cout << ans;

	return 0; 
}