#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map<ll, ll> m;
	ll max = 0, card, num;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (i == 0) {
			card = num;
			max = 1;
		}

		if (m.find(num) != m.end()) {
			m[num]++;
			if (max < m[num]) {
				max = m[num];
				card = num;
			}
			else if (max == m[num] && card > num) card = num;
		}
		else m.insert(pair<ll, ll>(num, 1));
		if (max == 1 && card > num) card = num;
	}

	cout << card;
	return 0;
}