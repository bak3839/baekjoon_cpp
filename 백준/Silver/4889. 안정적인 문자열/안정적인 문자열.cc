#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string str;
int N = 1;

void Solution() {
    stack<char> s;
    int ans = 0;

    for (int i = 0; i < str.size(); i++) {       
        if (str[i] == '{') s.push('{');

        else if (s.empty() && str[i] == '}') {
            ans++;
            s.push('{');
        }

        else if (!s.empty() && str[i] == '{') {
            ans++;
            s.pop();
        }

        else if (!s.empty() && str[i] == '}') s.pop();
    }
    
    if (!s.empty()) ans += s.size() / 2;

    cout << N++ << ". " << ans << "\n";
}

bool Input() {    
    cin >> str;

    if (str[0] == '-') return false;
    return true;
}

void Solve() {
    while (1) {
        if (!Input()) break;
        Solution();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
