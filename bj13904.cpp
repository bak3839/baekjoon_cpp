#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
	int d;
	int w;
}task;

struct cmp{
	bool operator()(task t1, task t2) {
		if (t1.w > t2.w) return 1;
		else return 0;
	}
};

bool cmp2(task t1, task t2) {
	if (t1.d < t2.d) return 1;
	else if (t1.d == t2.d) {
		if (t1.w > t2.w) return 1;
		else return 0;
	}
	else return 0;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<task, vector<task>, cmp> pq;
	vector<task> v;
	task t;

	int N, d, w, day = 1 , sum = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> d >> w;
		t.d = d;
		t.w = w;
		v.push_back(t);
	}

	sort(v.begin(), v.end(), cmp2);

	for (int i = 0; i < N; i++) {
		if (day <= v[i].d) {
			pq.push(v[i]);
			sum += v[i].w;
			day++;
		}

		else if (pq.top().w < v[i].w && day - 1 == v[i].d) {
			sum -= pq.top().w;
			pq.pop();
			pq.push(v[i]);
			sum += v[i].w;
		}
	}

	cout << sum;
	return 0;
}