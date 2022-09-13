#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef struct {
	string name;
	int month;
	int year;
	int day;
}Data;


bool cmp(Data d1, Data d2) {
	if (d1.year > d2.year) return 1;
	else if (d1.year == d2.year) {
		if (d1.month > d2.month) return 1;
		else if (d1.month == d2.month) {
			if (d1.day > d2.day) return 1;
			else return 0;
		}
		else return 0;
	}
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<Data> v;
	string name;
	Data d;
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> d.name >> d.day >> d.month >> d.year;
		v.push_back(d);
	}

	sort(v.begin(), v.end(), cmp);

	cout << v.front().name << "\n" << v.back().name;
	return 0;
}