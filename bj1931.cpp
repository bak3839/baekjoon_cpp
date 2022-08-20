#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int s;
	int e;
}Time;

bool cmp(Time n1, Time n2) {
	if (n1.e < n2.e) return 1;
	else if (n1.e == n2.e) {
		if (n1.s < n2.s) return 1;
		else return 0;
	}
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<Time> v;
	Time T;
	int ts, te, N, count = 1;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> ts >> te;
		T.s = ts;
		T.e = te;

		v.push_back(T);
	}

	sort(v.begin(), v.end(), cmp);
	
	te = v[0].e;

	for (int i = 1; i < N; i++) {
		if (te <= v[i].s) {
			count++;
			te = v[i].e;
		}
	}

	cout << count;
	return 0;
}