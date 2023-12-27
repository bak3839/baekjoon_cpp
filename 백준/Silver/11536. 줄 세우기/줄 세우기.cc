#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> name;
vector<string> ic;
vector<string> dc;


void Solution() {

	for (int i = 0; i < N; i++) {
		ic[i] = name[i];
		dc[i] = name[i];
	}
	sort(dc.begin(), dc.end(), greater<string>());
	sort(ic.begin(), ic.end());

	bool increase = true;

	for (int i = 0; i < N; i++) {
		if (name[i] != ic[i]) {
			increase = false;
			break;
		}
	}

	if (increase) {
		cout << "INCREASING";
		return;
	}

	bool decrease = true;

	for (int i = 0; i < N; i++) {
		if (name[i] != dc[i]) {
			decrease = false;
			break;
		}
	}

	if (decrease) {
		cout << "DECREASING";
		return;
	}

	cout << "NEITHER";
}

void Input() {
	cin >> N;

	ic.resize(N);
	dc.resize(N);
	name.resize(N);

	for (int i = 0; i < N; i++)
		cin >> name[i];
}

void Solve() {
	Input();
	Solution();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Solve();
	return 0;
}