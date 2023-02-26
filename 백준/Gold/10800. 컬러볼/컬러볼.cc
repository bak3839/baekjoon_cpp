#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, c, s;
	cin >> N;
	vector<vector<int>> v(N + 1, vector<int>(3, 0));
	vector<int> ans(N + 1);
	vector<int> sum(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		cin >> c >> s;
		v[i] = { s, c ,i };
	}
	sort(v.begin(), v.end());

	bool dup = false;
	int size, color, idx, same_sum = 0, res, save = 0;
	for (int i = 1; i <= N; i++) {
		size = v[i][0]; color = v[i][1]; idx = v[i][2];

		if (i > 1 && v[i - 1][0] - v[i - 2][0] == size && color == v[i - 1][1]) save += size;
		else if (i > 1 && v[i - 1][0] - v[i - 2][0] == size) {
			same_sum += (size + save);
			save = 0;
		}
		else {
			same_sum = 0;
			save = 0;
		}
		
		res = v[i - 1][0] - sum[color] - same_sum;
		if (res < 0) ans[idx] = 0;
		else ans[idx] = res;
		sum[color] += size;
		v[i][0] += v[i - 1][0];
	}

	for (int i = 1; i <= N; i++) cout << ans[i] << "\n";
	return 0;
}