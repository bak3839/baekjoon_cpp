#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int money, N, a, b;
	ll sum = 0;

	cin >> money >> N;

	for (int i = 0;i < N;i++) {
		cin >> a >> b;
		sum += (a * b);
	}

	if (sum == money) cout << "Yes";
	else cout << "No";
	return 0;
}