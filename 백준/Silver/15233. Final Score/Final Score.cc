#include <iostream>
#include <vector>
#include <map>

using namespace std;

int a, b, g;
map<string, char> m;

void Solution() {
    int A = 0, B = 0;
    string name;

    for (int i = 0; i < g; i++) {
        cin >> name;

        if (m[name] == 'A') A++;
        else B++;
    }

    if (A > B) cout << 'A';
    else if (A < B) cout << 'B';
    else cout << "TIE";
}

void Input() {
    string name;
    cin >> a >> b >> g;

    for (int i = 0; i < a; i++) {
        cin >> name;
        m[name] = 'A';
    }

    for (int i = 0; i < b; i++) {
        cin >> name;
        m[name] = 'B';
    }
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