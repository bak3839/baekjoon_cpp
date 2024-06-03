#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void Solution(int n) {
    int res = 0;

    for (int i = 0; i < 20; i++) {
        for (int j = i; j < 20; j++) {
            if (v[i] > v[j]) res++;
        }
    }
    cout << n << " " << res << "\n";
}

void Input() {
    int n;
    cin >> n;

    v.resize(20);

    for (int i = 0; i < 20; i++) {
        cin >> v[i];
    }
}

void Solve() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        Input();
        Solution(i);
        v.clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}