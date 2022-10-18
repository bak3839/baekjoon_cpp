#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int n1, n2, index = 0, x, y;

	while (s[index] != ':') index++;
	n1 = stoi(s.substr(0, index));
	n2 = stoi(s.substr(index + 1));

	x = n1; y = n2;

	if (n1 > n2) {
		while (y != 0) {
			int t = x % y;
			x = y;
			y = t;
		}
		cout << n1 / x << ":" << n2 / x;
	}

	else {
		while (x != 0) {
			int t = y % x;
			y = x;
			x = t;
		}
		cout << n1 / y << ":" << n2 / y;
	}

	return 0;
}