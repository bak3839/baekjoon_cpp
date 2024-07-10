#include <iostream>
#include <stack>

using namespace std;

int N;
string str;

void Solution() {
    bool pass = true;
    stack<char> s;

    for (int i = 0; i < N; i++) {
        if (str[i] == '>') {
            s.push(str[i]);
            continue;
        }

        if (s.empty()) {
            pass = false;
            break;
        }

        s.pop();
    }

    if (s.empty() && pass) cout << "legal\n";
    else cout << "illegal\n";
}

void Input() {
    cin >> N >> str;
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}