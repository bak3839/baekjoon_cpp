#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());

	cout << v[0] << " ";

	for (int i = 1; i < N; i++) {
		if (v[i - 1] == v[i]) continue;
		cout << v[i] << " ";
	}
	return 0;
}