#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool pass = false;
string s, target;

void Search(string str) {
    if (str.size() == s.size()) {
        if (str == s) pass = true;
        return;
    }

    if (str[0] == 'B') {
        string B = str;

        for (int i = 0; i < B.size() / 2; i++) {
            char ch = B[i];
            B[i] = B[B.size() - 1 - i];
            B[B.size() - 1 - i] = ch;
        }

        Search(B.substr(0, str.size() - 1));    
    }

    if (pass) return;

    if (str.back() == 'A') 
        Search(str.substr(0, str.size() - 1));

    if (pass) return;
}

void Solution() {
    Search(target);

    if (pass) cout << 1;
    else cout << 0;
}

void Input() {
    cin >> s >> target;
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
