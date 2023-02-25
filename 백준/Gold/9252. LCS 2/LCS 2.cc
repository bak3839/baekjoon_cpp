#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int ans = 0;
	string s1, s2, res = "";
	cin >> s1 >> s2;

	vector<vector<int>> lcs(s2.size() + 1, vector<int>(s1.size() + 1, 0));

	for (int i = 1; i <= s2.size(); i++) {
		for (int j = 1; j <= s1.size(); j++) {
			if (s2[i - 1] == s1[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;

			else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}

	ans = lcs[s2.size()][s1.size()];
	int x = s2.size(), y = s1.size();

	while (res.size() != ans) {
		int now = lcs[x][y];

 		if (now == 0) break;

		if (now == lcs[x - 1][y] + 1 && now == lcs[x][y - 1] + 1) {
			res.push_back(s2[x - 1]);
			x--; y--;
		}

		else if (now == lcs[x][y - 1]) y--;
		else x--;
	}

	cout << ans;
	if (res.size() != 0) {
		cout << "\n";
		for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
	}	
	return 0;
}