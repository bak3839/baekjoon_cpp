#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> v;
	int T, N, h;

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> h;
			v.push_back(h);
		}

		sort(v.begin(), v.end());

		int left = 0, right = v.size() - 1, index = 0, res = 0;
		vector<int> tmp(v.size());

		while (left < v.size() / 2 && right >= v.size() / 2) {
			tmp[left] = v[index++];
			tmp[right] = v[index++];

			if (left == 0) {
				if (tmp[right] - tmp[left] > res) res = tmp[right] - tmp[left];
			}

			else {
				if (tmp[left] - tmp[left - 1] > res) res = tmp[left] - tmp[left - 1];
				if(tmp[right] - tmp[right + 1] > res) res = tmp[right] - tmp[right + 1];
			}
			left++;
			right--;
		}

		if (v.size() % 2 != 0) {
			tmp[v.size() / 2] = v[index];
			if (tmp[left] - tmp[left - 1] > res) res = tmp[left] - tmp[left - 1];
			if (tmp[right] - tmp[right + 1] > res) res = tmp[right] - tmp[right + 1];
		}

		else {
			if (tmp[right + 1] - tmp[left - 1] > res) res = tmp[right + 1] - tmp[left - 1];
		}
		v.clear();
		tmp.clear();
		cout << res << "\n";
	}
	return 0;
}