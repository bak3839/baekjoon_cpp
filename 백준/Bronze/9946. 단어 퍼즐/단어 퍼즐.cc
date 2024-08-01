#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string A, B;

void Solution(int count) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    cout << "Case " << count << ": ";

    if (A == B) cout << "same\n";
    else cout << "different\n";
}

void Input() {
    int count = 1;

    while (1) {
        cin >> A >> B;

        if (A == "END" && B == "END") break;

        Solution(count++);
    }
}

void Solve() {
    Input();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}