#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
string num;

void Solution() {
    for (int i = 0; i < num.size(); i++) {
        int res = 0;
        char ch = num[i];

        if ('0' <= ch && ch <= '9') {
            s.push(ch - '0');
        }
        else {
            int first = s.top();
            s.pop();

            int second = s.top();
            s.pop();

            if (ch == '+') res = (second + first);
            else if (ch == '-') res = (second - first);
            else if (ch == '/') res = (second / first);
            else res = (second * first);

            s.push(res);
        }
    }

    cout << s.top();
}

void Input() {
    cin >> num;
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}