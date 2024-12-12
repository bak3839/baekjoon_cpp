#include <iostream>
#include <stack>
#include <vector>

inline int isOpen(char ch) {
    if(ch == '(') return 1;
    else if(ch == '{') return 2;
    else if(ch == '[') return 3;
    return 0;
}

inline int isClose(char ch) {
    if(ch == ')') return 1;
    else if(ch == '}') return 2;
    else if(ch == ']') return 3;
    return 0;
}

using namespace std;

string S;

void Solution() {
    int res = 0, sum = 0, open, close;
    stack<char> stack;
    vector<int> ans(10, 0);

    for(auto ch : S) {
        open = isOpen(ch);
        close = isClose(ch);

        if(open > 0) {
            sum += open;
        } 
        else if(close > 0) {
            sum -= close;
        }
        else {
            res = max(res, sum);
        }
    }
    cout << res;
}

void Input() {
    cin >> S;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
    return 0;
}