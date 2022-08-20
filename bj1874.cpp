#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	stack<int> s;
	vector<char> result;
	vector<int> v;

	int n, num = 0, vindex = 0, rindex = 0, count = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	while (vindex < n){
		if (count < v[vindex]) {
			for (int i = count + 1; i < v[vindex]; i++) { // count는 현재 몇번째까지 push했는지 나타내는 변수
				s.push(i);
				result.push_back('+');
			}
			result.push_back('+');
			result.push_back('-');
			count = v[vindex++];
		}

		else if (count > v[vindex]) {
			if (s.top() != v[vindex++]) {
				cout << "NO";
				return 0;
			}
			s.pop();
			result.push_back('-');	
		}
	}

	for (int i = 0; i < result.size(); i++) cout << result[i] << "\n";
	return 0;
}