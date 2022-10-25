#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int h = 0, c = 0, b = 0, sum = 0;
	cin >> h;
	b = h;
	for (int i = 0; i < 2; i++) {
		cin >> h;
		b = min(b, h);
	}
	sum += b;

	cin >> h;
	cin >> c;
	cout << sum + min(h, c) - 50;
	return 0;
}