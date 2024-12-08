#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
    stack<char> stack;

    string S;
    cin >> S;

    for (auto ch : S) {
        if (ch == '(') stack.push('(');
        else if (ch == ')' && !stack.empty()) stack.pop();
        else break;
    }

    cout << stack.size();
    return 0;
}