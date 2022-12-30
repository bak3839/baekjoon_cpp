#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	double res, w, p;
	char ch;

	for (int i = 1; i <= 3; i++) {
		cin >> p >> w;

		if (p * 10 >= 5000) p = p * 10 - 500;
		else p = p * 10;
		w = w * 10;

		if (i == 1) {
			res = w / p;
			ch = 'S';
		}

		else if (i == 2) {
			if (res < w / p) {
				res = w / p;
				ch = 'N';
			}
		}

		else if (i == 3) {
			if (res < w / p) {
				res = w / p;
				ch = 'U';
			}
		}
	}
	cout << ch;
	return 0;
}