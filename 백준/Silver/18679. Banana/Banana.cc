#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, T;
map<string, string> m;

void Solution() {
    int K;
    string key;

    for (int i = 0; i < T; i++) {
        cin >> K;

        for (int i = 0; i < K; i++) {
            cin >> key;
            cout << m[key] << " ";
        }
        cout << "\n";
    }
}

void Input() {
    string key, value, mid;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> key >> mid >> value;
        m[key] = value;
    }

    cin >> T;
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