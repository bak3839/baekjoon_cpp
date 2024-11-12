#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	string str;
	cin >> str;

	int cnt = 0;
    
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            cnt++;
	}
	cout << cnt;
    
    return 0;
}