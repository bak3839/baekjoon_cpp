#include <iostream>
#include <vector>

using namespace std;

int cnt = 1;
string str;
vector<bool> choice;

void Search(string ans, int len) {
    if (ans.size() == len) {
        cout << ans << "\n";
        return;
    }

    for (int i = 0; i < len; i++) {
        if (choice[i]) continue;

        choice[i] = true;
        Search(ans + str[i], len);
        choice[i] = false;
    }
}

void Solution() {
    choice.resize(str.size(), false);

    Search("", str.size());
    choice.clear();
}

void Input() {
    cin >> str;
}

void Solve() {
    int T;
    cin >> T;

    while (T--) {
        cout << "Case # " << cnt++ << ":\n";
        Input();
        Solution();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}