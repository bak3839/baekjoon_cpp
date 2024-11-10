#include <iostream>

using namespace std;

int main() {
	int count = 0, out, in, ans = 0;

	for (int i = 0; i < 10; i++) {
		cin >> out >> in;

		count -= out;
		count += in;

		if (count > 10000) count = 10000;

		ans = max(ans, count);
	}

	cout << ans;
	
	return 0;
}