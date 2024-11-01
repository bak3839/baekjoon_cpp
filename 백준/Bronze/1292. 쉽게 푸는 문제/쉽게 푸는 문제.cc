#include <iostream>
#include <vector>

using namespace std;

int main() {
	bool finish = false;
	int n, m, ans = 0, index = 1;

	cin >> n >> m;

	vector<int> res(1001);

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < i; j++) {
			res[index++] = i;

			if (index > m) {
				finish = true;
				break;
			}
		}

		if (finish) break;
	}

	for (int i = n; i <= m; i++) 
		ans += res[i];

	cout << ans;
	return 0;
}