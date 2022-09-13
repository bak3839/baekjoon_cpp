#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, num, index1 = 0, index2 = 0;
	vector<int> v1, v2;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v1.push_back(num);
	}

	for (int i = 0; i < M; i++) {
		cin >> num;
		v2.push_back(num);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	while (index1 < N && index2 < M) {
		if (v1[index1] < v2[index2]) cout << v1[index1++] << " ";
		else cout << v2[index2++] << " ";
	}

	while (index1 < N) cout << v1[index1++] << " ";
	while (index2 < M) cout << v2[index2++] << " ";
	return 0;
}