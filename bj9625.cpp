#include <iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int k, a, A = 0, B = 1;
	cin >> k;

	for (int i = 1; i < k; i++) {
		a = B;
		B += A;
		A = a;
	}

	cout << A << " " << B;
	return 0;
}