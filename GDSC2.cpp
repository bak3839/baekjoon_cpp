#include <iostream>

using namespace std;

int main() {
	int N, res, rest = 0, cnt = 0;
	cin >> N;
	res = N;

	do {
		rest = (res % 10);
		res = (res / 10) + rest;

		if (res < 10) res = rest * 10 + res;

		else res = (rest * 10) + (res % 10);

		cnt++;
	} while (res != N);

	cout << cnt;
	return 0;
}