#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int s;
	int e;
}Time;

bool cmp(Time t1, Time t2) {
	if (t1.s < t2.s) return 1;
	else if (t1.s == t2.s) {
		if (t1.e < t2.e) return 1;
		else return 0;
	}
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq;
	vector<Time> v;
	Time T;
	int N, s, e;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		T.s = s;
		T.e = e;
		v.push_back(T);
	}

	sort(v.begin(), v.end(), cmp);
	pq.push(v[0].e);

	for (int i = 1; i < N; i++) {
		if (v[i].s < pq.top()) pq.push(v[i].e);
		else {
			pq.pop();
			pq.push(v[i].e);
		}
	}

	cout << pq.size();
	return 0;
}