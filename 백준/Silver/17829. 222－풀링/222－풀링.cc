#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int mat[1024][1024];
int n;

int divisionConquer(int half, int x, int y) {
	vector<int> v;

	if (half == 1) {
		v.push_back(mat[y][x]);
		v.push_back(mat[y][x + 1]);
		v.push_back(mat[y + 1][x]);
		v.push_back(mat[y + 1][x + 1]);
		sort(v.begin(), v.end());
		return v[2];
	}

	else {
		v.push_back(divisionConquer(half / 2, x, y));
		v.push_back(divisionConquer(half / 2, x + half, y));
		v.push_back(divisionConquer(half / 2, x, y + half));
		v.push_back(divisionConquer(half / 2, x + half, y + half));
		sort(v.begin(), v.end());
		return v[2];
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];

	cout << divisionConquer(n / 2, 0, 0);
	return 0;
}