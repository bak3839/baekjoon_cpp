#include <iostream>
#include <vector>

using namespace std;

string s, t;

int gcd(int a, int b) {
    int c;

    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

void Solution() {
    bool pass = true;
    string S = "", L = "";

    if (s.size() > t.size()) {
        L = s;
        S = t;
    }
    else {
        L = t;
        S = s;
    }

    int sLen = S.size(), lLen = L.size();
    int target = (sLen * lLen) / gcd(sLen, lLen);

    string sTmp = S, lTmp = L;

    while (S.size() != target) {
        S.append(sTmp);
    }

    while (L.size() != target) {
        L.append(lTmp);
    }

    cout << (S == L ? 1 : 0);
}

void Input() {
    cin >> s >> t;
}

void Solve() {
    Input();
    Solution();
}

int main() {
    Solve();
    return 0;
}