#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int N;

void Solution() {
    map<string, int> m;
    string file, str;

    for (int i = 0; i < N; i++) {
        int cnt = 0;
        cin >> file;

        stringstream ss(file);

        while (getline(ss, str, '.')) {
            if (cnt++ == 0) continue;
 
            m[str]++;
        }
    }

    for (auto name : m) 
        cout << name.first << " " << name.second << "\n";
}

void Input() {
    cin >> N;
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
