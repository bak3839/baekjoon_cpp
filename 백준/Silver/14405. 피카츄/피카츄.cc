#include <iostream>
#include <vector>

using namespace std;

string S;

void Solution() {
    int index = 0;
    bool pass = true;

    while (index < S.size()) {
        if (index + 1 < S.size() && S[index] == 'p' && S[index + 1] == 'i') index += 2;
        else if (index + 1 < S.size() && S[index] == 'k' && S[index + 1] == 'a') index += 2;
        else if (index + 2 < S.size() && S[index] == 'c' && S[index + 1] == 'h' && S[index + 2] == 'u') index += 3;

        else {
            pass = false;
            break;
        }
    }

    cout << (pass ? "YES" : "NO");
}

void Input() {
    cin >> S;
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