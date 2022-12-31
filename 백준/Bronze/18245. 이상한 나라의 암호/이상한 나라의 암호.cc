#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	int cnt = 1;
	while (1) {
		string res = "";
		getline(cin, s);
		if (s == "Was it a cat I saw?") break;

		for (int i = 0; i < s.size(); i = i + cnt + 1) {
			res.push_back(s[i]);
		}
		
		cout << res << "\n";
		cnt++;
	}

	return 0;
}