#include <iostream>

using namespace std;
using ll = long long;

ll A, B;

int gcd(ll a, ll b) {
	ll c;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

void Solution() {
	cout << (A * B) / gcd(A, B);
}

void Input() {
	cin >> A >> B;
}

void Solve() {
    Input();
    Solution();
}

int main() {
    Solve();
    return 0;
}