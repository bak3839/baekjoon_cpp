#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int x;
	int y;
}dot;

bool cmp(dot n1, dot n2) {
	if (n1.x < n2.x) return 1;
	else if (n1.x == n2.x) {
		if (n1.y <= n2.y) return 1;
		else return 0;
	}
	else return 0;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<dot> v;

	int N;
	dot d;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> d.x >> d.y;
		v.push_back(d);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << v[i].x << " " << v[i].y << "\n";
	}
	return 0;
}