#include <iostream>
#include <cmath>

using namespace std;

void Solution() {

}

void Input() {
    string str;
    cin >> str;

    int n = sqrt(str.size());

    for(int i = n - 1; i >= 0; i--) {
        for(int j = i; j < str.size(); j = j + n) {
            cout << str[j];
        }
    }
    cout << "\n";
}

void Solve() {
    int T;
    cin >> T;

    while(T--) {
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