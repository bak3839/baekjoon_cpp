#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s, ans = "";
	int N;
	cin >> N >> s;

	if (N <= 25) cout << s;

	else {
		bool pass = true;

		for (int i = 11; i < (N - 12); i++) {
			if (s[i] == '.') {
				pass = false;
				break;
			}
		}
		
		if (pass) { // 존재함
			ans.append(s.substr(0, 11));
			ans.append("...");
			ans.append(s.substr(N - 11, 11));
		}

		else {
			ans.append(s.substr(0, 9));
			ans.append("......");
			ans.append(s.substr(N - 10, 11));
		}
	}

	cout << ans;
	return 0;
}