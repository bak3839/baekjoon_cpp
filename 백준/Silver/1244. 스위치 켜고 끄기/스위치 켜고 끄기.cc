#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, s, index;
	cin >> N;
	s = N + 1;
	vector<int> v(s);
	for (int i = 1; i <= N; i++) {
		cin >> s;
		v[i] = s;
	}
	
	cin >> M;

	for (int i = 0; i < M; i++) {
		
		cin >> s >> index;
		if (s == 1) {
			int k = 2, in = index;
			while (in <= N) {
				if (v[in] == 0) v[in] = 1;
				else v[in] = 0;
				in = index * k;
				k++;
			}
		}

		else {
			int left = index - 1, right = index + 1;
			if (v[index] == 0) v[index] = 1;
			else v[index] = 0;
			while (left > 0 && right <= N) {
				if (v[left] == v[right]) {
					if (v[left] == 0) {
						v[left] = 1;
						v[right] = 1;
					}
					else {
						v[left] = 0;
						v[right] = 0;
					}
				}
				else break;
				--left;
				++right;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << v[i] << " ";
		if (i % 20 == 0) cout << "\n";
	}
	return 0;
}