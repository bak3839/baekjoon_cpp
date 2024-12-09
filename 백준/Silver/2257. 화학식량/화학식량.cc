#include <iostream>
#include <stack>

using namespace std;

string molecule;

int CheckAtom(char ch) {
    if (ch == 'H') return 1;
    else if (ch == 'C') return 12;
    else if (ch == 'O') return 16;
    return -1;
}

void Solution() {
    char now;
    int ans = 0, atom, base, sum = 0;
    stack<int> s;

    for (int i = 0; i < molecule.size(); i++) {
        now = molecule[i];
        atom = CheckAtom(now);

        if (now == '(') s.push(-1);
        else if (now == ')') {
            sum = 0;

            while (s.top() != -1) {
                sum += s.top();
                s.pop();
            }
            s.pop();
            s.push(sum);
        }
        else if (atom != -1) s.push(atom);
        else {
            sum = s.top() * (now - '0');
            s.pop();
            s.push(sum);
        }
    }

    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }

    cout << ans;
}

void Input() {
    cin >> molecule;
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}