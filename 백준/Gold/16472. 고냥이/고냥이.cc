#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	int N, l = -1, r = 0, cnt = 0, res = 0;

	cin >> N;
	vector<int> alpha(26, 0); // a = 97

	cin >> s;

	alpha[s[r] - 97] = 1;
	++cnt;

	while (l < r) {
		char ch;

		if (r + 1 >= s.size()) break;

		if (cnt < N) {
			ch = s[++r] - 97;

			if (alpha[ch] == 0) {
				++alpha[ch];
				++cnt;
			}

			else {
				++alpha[ch];
			}

			res = max(res, r - l);
		}

		else if (cnt == N) {
			ch = s[r + 1] - 97;

			if (alpha[ch] == 0) { // 새로운 알파벳
				if (--alpha[s[++l] - 97] == 0) {
					++r;
					++alpha[ch];
				}
			}

			else {
				++alpha[ch];
				++r;
				res = max(res, r - l);
			}
		}
	}

	cout << res;
	
	return 0;
}