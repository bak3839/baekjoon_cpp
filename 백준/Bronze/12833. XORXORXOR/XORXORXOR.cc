#include <iostream>

using namespace std;

int A, B, C;

void Solution() {
    if(C % 2) cout << (A ^ B);
    else cout << A;
}

void Input() {
    cin >> A >> B >> C;
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