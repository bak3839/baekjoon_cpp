#include <bits/stdc++.h>
#define prev ddd

using namespace std;

int idx1, idx2, prev = 0;
string num1, num2;
stack<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> num1 >> num2;
    idx1 = num1.size() - 1, idx2 = num2.size() - 1;

    while (idx1 >= 0 || idx2 >= 0) {
        int n1 = 0, n2 = 0, res = 0;

        if (idx1 >= 0) n1 = num1[idx1--] - '0';
        if (idx2 >= 0) n2 = num2[idx2--] - '0';

        res = n1 + n2 + prev;
        prev = res / 10;
        s.push(res % 10);
    }

    if (prev > 0) s.push(prev);

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    return 0;
}