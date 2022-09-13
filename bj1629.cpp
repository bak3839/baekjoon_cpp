#include <iostream>

using namespace std;

typedef long long ll;

ll solution(ll A, ll B, ll C) {
	if (B == 0) return 1;
	ll res = solution(A, B / 2, C);
	res = res * res % C;
	if (B % 2 == 0) return res % C;
	else return res * A % C;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll A, B, C;

	cin >> A >> B >> C;
	cout << solution(A, B, C);
	return 0;
}