#include <iostream>
#include <vector>

using namespace std;

string a, b;

void Solution() {
    string s;

    for (int i = 0; i < 16; i++) {
        if (i % 2) s.push_back(b[i / 2]);
        else s.push_back(a[i / 2]);
    }
    
    while (s.size() > 2) {
        string tmp;

        for (int i = 0; i < s.size() - 1; i++) {
            int mod = ((s[i] - 48) + (s[i + 1] - 48)) % 10;
            tmp.push_back(mod + 48);
        }
        s = tmp;
    }
    cout << s;
}

void Input() {
    cin >> a >> b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}