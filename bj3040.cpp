#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	bool pass = false;
	int num, x1, x2, sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> num;
		sum += num;
		v.push_back(num);
	}

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - v[i] - v[j] == 100) {
				x1 = i;
				x2 = j;
				pass = true;
				break;
			}
		}
		if (pass == true) break;
	}

	for (int i = 0; i < 9; i++) {
		if (i != x1 && i != x2) cout << v[i] << "\n";
	}
	return 0;
}