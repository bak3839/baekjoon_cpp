#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
	int s;
	int t;
}Time;

bool cmp(Time t1, Time t2) {
	if (t1.s < t2.s) return 1;
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<Time> v;
	Time t;
	int N, sum, res;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t.s >> t.t;
		v.push_back(t);
	}

	sort(v.begin(), v.end(), cmp);
	sum = v[0].s + v[0].t; 

	for (int i = 1; i < N; i++) {
		if (v[i].s > sum) sum += v[i].s - sum + v[i].t;
		else sum += v[i].t;
	}

	cout << sum;
	return 0;
}