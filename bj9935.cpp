#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str, bomb, res;
	cin >> str >> bomb;
	int len = bomb.size(), cnt;

	for (int i = 0; i < str.size(); i++) {
		cnt = 0;
		res.push_back(str[i]);

		if (res.size() >= len) {
			for (int j = 0; j < len; j++) {
				if (res[res.size() - 1 - j] == bomb[len - 1 - j]) cnt++;
				else break;
			}
		}

		if (cnt == len) {
			for (int i = 0; i < len; i++) res.pop_back();
		}
	}

	if (res.size() == 0) cout << "FRULA";
	else cout << res;
	return 0;
}