#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;

void Solution() {
    sort(num.begin(), num.end(), greater<int>());

    cout << num[2] << "\n";
}

void Input() {
    num.resize(10);

    for (int i = 0; i < 10; i++)
        cin >> num[i];
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        Input();
        Solution();
        num.clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}