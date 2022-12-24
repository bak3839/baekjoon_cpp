#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> v(3);
	vector<int> dp_min(3, 0);
	vector<int> dp_max(3, 0);

	for (int i = 0; i < N; i++) {
		int max0 = dp_max[0];
		int max1 = dp_max[1];
		int max2 = dp_max[2];

		int min0 = dp_min[0];
		int min1 = dp_min[1];
		int min2 = dp_min[2];

		for (short j = 0; j < 3; j++) {
			cin >> v[j];
			if (i == 0) {
				dp_min[j] = v[j];
				dp_max[j] = v[j];
			}

			else {
				if (j == 0) {
					dp_max[j] = max(max0 + v[j], max1 + v[j]);
					dp_min[j] = min(min0 + v[j], min1 + v[j]);
				}

				else if (j == 1) {
					dp_max[j] = max(max0 + v[j], max(max1 + v[j], max2 + v[j]));
					dp_min[j] = min(min0 + v[j], min(min1 + v[j], min2 + v[j]));
				}

				else {
					dp_max[j] = max(max2 + v[j], max1 + v[j]);
					dp_min[j] = min(min2 + v[j], min1 + v[j]);
				}
			}
		}
	}

	cout << max(dp_max[0], max(dp_max[1], dp_max[2])) << " " << min(dp_min[0], min(dp_min[1], dp_min[2]));
	return 0;
}